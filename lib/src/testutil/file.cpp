#include "testutil/file.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>

namespace {

static constexpr int kBufSize = 4096;
static const std::string kTestDataDirName{"test_data"};

std::string ReadAll(std::istream &input) {
  std::ostringstream output;
  char buf[kBufSize];
  while (input) {
    input.read(buf, kBufSize);
    auto count = input.gcount();
    for (int i = 0; i < count; i++) {
      output << buf[i];
    }
  }
  return output.str();
}

std::filesystem::path DataFilePath(const std::string &source_location,
                                   const std::string &filename) {
  std::filesystem::path source_file_path{source_location};
  return source_file_path.parent_path() / kTestDataDirName / filename;
}

}  // namespace

std::string testutil::FileBasedTest(
    testutil::Solution solution, const std::string &source_location,
    const std::string input_filename,
    const std::string &expected_output_filename) {
  std::ifstream input_stream(DataFilePath(source_location, input_filename));
  std::ifstream expected_stream(
      DataFilePath(source_location, expected_output_filename));
  auto expected = ReadAll(expected_stream);
  std::ostringstream output_stream;
  solution(input_stream, output_stream);
  auto output = output_stream.str();
  if (output == expected) {
    return {};
  }
  std::stringstream diff;
  diff << "expected:\n";
  diff << expected << '\n';
  diff << "actual:\n";
  diff << output;
  return diff.str();
}
