#include <iostream>
#include <vector>
#include <filesystem>
#include <sstream>
#include <fstream>
#include <unordered_map>

class NaiveSolution {
 public:
  std::pair<std::pair<int, int>, std::pair<int, int>> Add(int x, int y) {
    xs_[x]++;
    ys_[y]++;
    return calcBoundingBox();
  }

  std::pair<std::pair<int, int>, std::pair<int, int>> Remove(int x, int y) {
    if (--(xs_[x]) == 0) {
      xs_.erase(x);
    }
    if (--(ys_[y]) == 0) {
      ys_.erase(y);
    }
    return calcBoundingBox();
  }

 private:
  std::unordered_map<int, int> xs_;
  std::unordered_map<int, int> ys_;

  std::pair<std::pair<int, int>, std::pair<int, int>> calcBoundingBox() const {
    if (xs_.size() > 0 && ys_.size() > 0) {
      bool is_first_x = true, is_first_y = true;
      int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
      for (auto it = xs_.begin(); it != xs_.end(); ++it) {
        if (is_first_x || it->first < min_x) {
          min_x = it->first;
        }
        if (is_first_x || it->first > max_x) {
          max_x = it->first;
        }
        is_first_x = false;
      }
      for (auto it = ys_.begin(); it != ys_.end(); ++it) {
        if (is_first_y || it->first < min_y) {
          min_y = it->first;
        }
        if (is_first_y || it->first > max_y) {
          max_y = it->first;
        }
        is_first_y = false;
      }
      return {{min_x, max_y}, {max_x, min_y}};
    }
    return {{0, 0}, {0, 0}};
  }
};

class Generator {
 public:
  Generator(std::vector<std::pair<int, int>> points)
      : points_(points), file_path_(__FILE__) {}

  void Generate() {
    bool has_to_add = true;
    int case_number = 1;
    for (auto to_add = points_; has_to_add;
         has_to_add = std::next_permutation(to_add.begin(), to_add.end())) {
      bool has_to_remove = true;
      for (auto to_remove = points_; has_to_remove;
           has_to_remove =
               std::next_permutation(to_remove.begin(), to_remove.end())) {
        NaiveSolution solution;
        std::vector<std::string> case_lines;
        for (auto [add_x, add_y] : to_add) {
          auto box = solution.Add(add_x, add_y);
          case_lines.emplace_back(formatCommand("Add", {add_x, add_y}, box));
        }
        for (int i = 0; i < to_remove.size(); i++) {
          if (i == to_remove.size() - 1) {
            break;
          }
          auto [remove_x, remove_y] = to_remove[i];
          auto box = solution.Remove(remove_x, remove_y);
          case_lines.emplace_back(
              formatCommand("Rem", {remove_x, remove_y}, box));
        }
        writeCase(case_lines, case_number);
        case_number++;
      }
    }
  }

 private:
  std::vector<std::pair<int, int>> points_;
  std::filesystem::path file_path_;

  void writeCase(const std::vector<std::string> &lines, int case_number) {
    auto case_path = file_path_;
    case_path.replace_filename(buildRelativeCasePath(case_number));
    std::ofstream output(case_path);
    if (!output.good()) {
      throw std::runtime_error{whenCantOpenPath(case_path)};
    }
    for (const auto &line : lines) {
      output << line << "\n";
    }
  }

  std::string whenCantOpenPath(const std::string &path) {
    return (std::stringstream{} << "can't open path " << path).str();
  }

  std::filesystem::path buildRelativeCasePath(int case_number) {
    std::stringstream path_str;
    path_str << "cases/permutation_" << case_number << ".txt";
    return {path_str.str()};
  }

  std::string formatCommand(
      const std::string &tag, std::pair<int, int> point,
      std::pair<std::pair<int, int>, std::pair<int, int>> box) {
    std::stringstream command;
    command << tag << " " << formatPoint(point) << " {"
            << formatPoint(box.first) << "," << formatPoint(box.second) << "}";
    return command.str();
  }

  std::string formatPoint(std::pair<int, int> point) {
    std::stringstream output;
    output << "{" << point.first << "," << point.second << "}";
    return output.str();
  }
};

int main() {
  Generator generator({{1, 1}, {1, 3}, {2, 2}, {3, 1}, {3, 3}});
  generator.Generate();
}
