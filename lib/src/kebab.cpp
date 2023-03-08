#include <iostream>
#include <string>

int main(int argc, char **argv) {
  std::string line;
  if (!std::getline(std::cin, line)) {
    return -1;
  }
  int w = 0;
  for (int i = 0; i < line.size(); i++) {
    if (line[i] == ' ' && w > 0) {
      line[w++] = '-';
    } else if (line[i] >= 'A' && line[i] <= 'Z') {
      line[w++] = line[i] + 32;
    } else {
      line[w++] = line[i];
    }
  }
  line.resize(w);
  std::cout << line << '\n';
  return 0;
}
