Solutions for coding problems.

Feel free to roast them or make suggestions via issues or any other way.

This code is distributed under [GPL v3](https://www.gnu.org/licenses/gpl-3.0.html).

## Running Go tests

```
$ go test ./...
```

## Compiling C++ solutions

Neither building C++ solutions nor testing them are not automated yet, but I will fix this soon.

Meanwhile you can compile manually. The commands below are given for clang because it's the compiler I use, but adapting the commands to another compiler should not be too difficult.

Compiling Hackerrank solutions (with clang):

```
clang++ -I <path to repo> -o bin/hackerrank-<problem name> --std=c++11 hackerrank/<problem name>/cpp/main.cpp
```
