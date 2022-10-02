#include <fstream>
#include <iostream>

static const std::string kHeaderPragma{"#pragma once"};
static const std::string kMainIncludes = R"(
#include <iostream>
)";
static const std::string kGeneratedCodeWarning =
    R"(// This code was generated, do not edit.
)";

static const std::string kMain = R"(
int main() { Solve(std::cin, std::cout); }
)";

void Generate(std::string source_path) {
  std::ifstream in_stream(source_path);
  std::string line;
  for (int lineno = 1; std::getline(in_stream, line); lineno++) {
    if (lineno == 1 && line != kHeaderPragma) {
      throw std::runtime_error{
          "CSES solution header file is expected to have '#pragma once' on its "
          "first line"};
    }
    if (lineno == 1) {
      std::cout << kGeneratedCodeWarning;
      std::cout << kMainIncludes;
      continue;
    }
    std::cout << line << '\n';
  }
  std::cout << kMain;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    throw std::runtime_error{"expected exactly 1 argument"};
  }
  Generate(argv[1]);
  return 0;
}
