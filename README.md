Solutions for coding problems.

Feel free to roast them or make suggestions via issues or any other way.

This code is distributed under [GPL v3](https://www.gnu.org/licenses/gpl-3.0.html).

## Requirements

- go 1.17
- cmake >= 3.10

## Running Go tests

```
$ make go-test
```

## Running C++ tests

C++ tests use [GoogleTest](https://github.com/google/googletest) and can be built & run with the following command:

```
$ make cpp-test
```

Building & running C++ tests relies on naming conventions:
- a test executable is build for any file in `problems/<namespace>/<problem name>/cpp` directory whose name matches `*_test.cpp` glob
- all other `.cpp` files in the same directory excluding `main.cpp` and `solution.cpp` are built and linked with the test executable.
- files are expected to be named using `snake_case`

This won't work with Hackerrank solutions as they are provided as a `main.cpp` file.

Otherwise, adding tests for a new solution is a matter of adding a `problems/<namespace>/<problem name>/cpp` and writing a GoogleTest test suite in a file named `<whatever in snake_case>_test.cpp`.
