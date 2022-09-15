#include <gtest/gtest.h>

#include "solution.hpp"

#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>

class MyselfBoundingBoxTest : public testing::TestWithParam<std::string> {};

class ICommand {
 public:
  virtual ~ICommand() {}
  virtual std::pair<std::pair<int, int>, std::pair<int, int>> Run(
      Solution &solution) = 0;
};

class AddCommand : public ICommand {
 public:
  AddCommand(int x, int y) : x_(x), y_(y) {}

  std::pair<std::pair<int, int>, std::pair<int, int>> Run(Solution &solution) {
    return solution.Add(x_, y_);
  }

 private:
  int x_, y_;
};

class RemoveCommand : public ICommand {
 public:
  RemoveCommand(int x, int y) : x_(x), y_(y) {}

  std::pair<std::pair<int, int>, std::pair<int, int>> Run(Solution &solution) {
    return solution.Remove(x_, y_);
  }

 private:
  int x_, y_;
};

static const std::string::size_type kCommandTagLength = 3;
static const std::string kAdd{"Add"}, kRem{"Rem"};

class Parser {
 public:
  Parser(const std::string &line)
      : line_(line), pos_(0), failed_(false), failure_reason_("") {}

  bool Failed() const { return failed_; }

  std::string FailureReason() const { return failure_reason_; }

  std::unique_ptr<ICommand> ParseCommand() {
    auto start = pos_;
    pos_ = line_.find(' ');
    if (pos_ == std::string::npos) {
      return fail(whenNoCommandTagEnd(line_));
    }
    if (pos_ != kCommandTagLength) {
      return fail(whenBadCommandTagLength(pos_, kCommandTagLength));
    }
    auto command_tag = line_.substr(0, pos_);
    if (command_tag != kAdd && command_tag != kRem) {
      return fail(whenUnknownCommandTag(command_tag));
    }
    pos_++;
    auto point = parsePoint();
    if (failed_) {
      return nullptr;
    }
    if (pos_ >= line_.size() || line_[pos_] != ' ') {
      return fail();
    }
    pos_++;
    if (command_tag == kAdd) {
      std::unique_ptr<ICommand> result(
          new AddCommand{point.first, point.second});
      return result;
    }
    std::unique_ptr<ICommand> result(
        new RemoveCommand{point.first, point.second});
    return result;
  }

  // Leaves pos_ at past-the-end character
  std::pair<std::pair<int, int>, std::pair<int, int>> ParseBoundingBox() {
    std::pair<std::pair<int, int>, std::pair<int, int>> result;
    auto start = pos_;
    if (pos_ >= line_.size()) {
      setFail("line ended before bounding box");
      return result;
    }
    if (line_[pos_] != '{') {
      setFail(whenUnexpectedChar(pos_, '{'));
      // setFail(whenBadBoundingBox(line_.substr(start)));
      return result;
    }
    if (line_[line_.size() - 1] != '}') {
      setFail(whenUnexpectedChar(line_.size() - 1, '}'));
      // setFail(whenBadBoundingBox(line_.substr(start)));
      return result;
    }
    pos_++;
    result.first = parsePoint();
    if (failed_) {
      return result;
    }
    if (pos_ >= line_.size() || line_[pos_] != ',') {
      if (pos_ >= line_.size()) {
        setFail(whenPosOverflow(pos_));
      } else {
        setFail(whenUnexpectedChar(pos_, ','));
        // setFail(whenBadBoundingBox(line_.substr(start)));
      }
      return result;
    }
    pos_++;
    result.second = parsePoint();
    if (failed_) {
      return result;
    }
    if (pos_ != line_.size() - 1) {
      setFail(whenUnexpectedPos(pos_, line_.size() - 1));
      // setFail(whenBadBoundingBox(line_.substr(start)));
      return result;
    }
    pos_ = line_.size();
    return result;
  }

 private:
  const std::string &line_;
  std::string::size_type pos_;
  bool failed_;
  std::string failure_reason_;

  std::unique_ptr<ICommand> fail() { return fail("invalid command line"); }

  std::unique_ptr<ICommand> fail(std::string &&reason) {
    setFail(std::move(reason));
    return nullptr;
  }

  void setFail(std::string &&reason) {
    failed_ = true;
    failure_reason_ = reason;
  }

  std::string whenNoCommandTagEnd(const std::string &line) const {
    return (std::stringstream{} << "line " << line << " has no command tag")
        .str();
  }

  std::string whenBadPoint(const std::string &point) const {
    return (std::stringstream{} << "bad point " << point).str();
  }

  std::string whenBadBoundingBox(const std::string &box) const {
    return (std::stringstream{} << "bad bounding box " << box).str();
  }

  std::string whenBadCommandTagLength(int length, int expected_length) const {
    return (std::stringstream{} << "got command tag of length " << length
                                << " != " << expected_length)
        .str();
  }

  std::string whenUnknownCommandTag(const std::string &tag) const {
    return (std::stringstream{} << "unknown command tag " << tag
                                << ", expected one of " << kAdd << " " << kRem)
        .str();
  }

  std::string whenUnexpectedChar(std::string::size_type pos,
                                 char expected_char) {
    std::string actual(1, line_[pos]), expected(1, expected_char);
    return (std::stringstream{} << "expected '" << expected << "' at position "
                                << pos << ", got '" << actual << "'")
        .str();
  }

  std::string whenPosOverflow(std::string::size_type pos) {
    return (std::stringstream{} << "position is >= line size (" << pos
                                << " >= " << line_.size() << ")")
        .str();
  }

  std::string whenUnexpectedPos(std::string::size_type pos,
                                std::string::size_type expected_pos) {
    return (std::stringstream{} << "position != expected (" << pos
                                << " != " << expected_pos << ")")
        .str();
  }

  // Leaves pos_ at first character after point end
  std::pair<int, int> parsePoint() {
    if (pos_ >= line_.size()) {
      setFail("line ended before point");
      return {};
    }
    auto point_end = line_.find('}', pos_);
    if (point_end == std::string::npos) {
      setFail("cannot find point end");
      return {};
    }
    if (pos_ >= point_end || line_[pos_] != '{' || line_[point_end] != '}') {
      setFail(whenBadPoint(line_.substr(pos_, point_end - pos_)));
      return {};
    }
    auto point_comma = line_.find(',', pos_);
    if (point_comma == std::string::npos || point_comma >= point_end ||
        point_comma != line_.rfind(',', point_end)) {
      setFail(whenBadPoint(line_.substr(pos_, point_end - pos_)));
      return {};
    }
    std::pair<int, int> result;
    try {
      result.first = std::stoi(line_.substr(pos_ + 1, point_comma - pos_ - 1));
      result.second =
          std::stoi(line_.substr(point_comma + 1, point_end - point_comma - 1));
    } catch (const std::invalid_argument &err) {
      setFail(whenBadPoint(line_.substr(pos_, point_end - pos_)));
    } catch (const std::out_of_range &err) {
      setFail(whenBadPoint(line_.substr(pos_, point_end - pos_)));
    }
    pos_ = point_end + 1;
    return result;
  }
};

TEST_P(MyselfBoundingBoxTest, RunCommands) {
  Solution solution;
  std::filesystem::path test_file_path(__FILE__);
  std::filesystem::path relative_test_case_path(GetParam());
  auto test_case_path = test_file_path;
  test_case_path.replace_filename(relative_test_case_path);
  std::ifstream test_input(test_case_path);
  EXPECT_TRUE(test_input.good());
  std::string line;
  int line_number = 0;
  while (std::getline(test_input, line)) {
    EXPECT_TRUE(test_input.good());
    line_number++;
    Parser parser(line);
    auto command = parser.ParseCommand();
    if (parser.Failed()) {
      FAIL() << "cannot parse command at line " << line_number << ": "
             << parser.FailureReason();
    }
    auto expected_bounding_box = parser.ParseBoundingBox();
    if (parser.Failed()) {
      FAIL() << "cannot parse bounding box at line " << line_number << ": "
             << parser.FailureReason();
    }
    auto bounding_box = command->Run(solution);
    EXPECT_EQ(bounding_box, expected_bounding_box) << "at line " << line_number;
  }
}

INSTANTIATE_TEST_SUITE_P(Permutation13756, MyselfBoundingBoxTest,
                         testing::Values("cases/permutation_13756.txt"));
