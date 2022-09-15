#!/bin/bash

for name in `find -E problems -regex '.*\.hpp|.*\.cpp'`
do
	clang-format --verbose -i "$name"
done
