#!/bin/sh

# Adapted from https://github.com/edsrzf/gofmt-git-hook (the only meaningful
# addition on my part is running clang-format)

test_fmt() {
    hash gofmt 2>&- || { echo >&2 "gofmt not in PATH."; exit 1; }
    hash clang-format 2>&- || { echo >&2 "clang-format not in PATH."; exit 1; }
    IFS='
'
    for file in `find . -name '*.go'`
    do
        output=`git cat-file -p :$file | gofmt -l 2>&1`
        if test $? -ne 0
        then
            output=`echo "$output" | sed "s,<standard input>,$file,"`
            syntaxerrors="${list}${output}\n"
        elif test -n "$output"
        then
            list="${list}${file}\n"
        fi
    done
    exitcode=0
    if test -n "$syntaxerrors"
    then
        echo >&2 "gofmt found syntax errors:"
        printf "$syntaxerrors"
        exitcode=1
    fi
    if test -n "$list"
    then
        echo >&2 "gofmt needs to format these files (run go fmt ./... and git add):"
        printf "$list"
        exitcode=1
    fi
    ./scripts/cpp-format.sh -n
    if test $? -ne 0
    then
        echo >&2 "C++ files need to be formatted (run make cpp-format and git add)"
        exitcode=1
    fi
    exit $exitcode
}

case "$1" in
    --about )
        echo "Check Go code formatting"
        ;;
    * )
        test_fmt
        ;;
esac
