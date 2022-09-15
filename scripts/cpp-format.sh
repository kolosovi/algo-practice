#!/bin/bash

IS_DRY_RUN=0
EXIT_CODE=0

while getopts ":n" option
do
    case $option in
        n ) IS_DRY_RUN=1
    esac
done

for name in `find -E problems -regex '.*\.hpp|.*\.cpp'`
do
    if [[ $IS_DRY_RUN -eq 1 ]]
    then
        clang-format -Werror -n "$name" || let "EXIT_CODE = 1"
    else
        clang-format --verbose -i "$name"
    fi
done

exit $EXIT_CODE
