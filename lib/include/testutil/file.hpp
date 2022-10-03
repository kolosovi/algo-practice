#pragma once

#include <istream>
#include <ostream>

namespace testutil {

using Solution = void (*)(std::istream &, std::ostream &);

std::string FileBasedTest(Solution solution, const std::string &source_location,
                          const std::string input_filename,
                          const std::string &expected_output_filename);

}  // namespace testutil
