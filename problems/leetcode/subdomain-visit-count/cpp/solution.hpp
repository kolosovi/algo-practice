#pragma once

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::string> subdomainVisits(
      std::vector<std::string> &cpdomains) {
    std::unordered_map<std::string, int> counts;
    for (const auto &cpdomain : cpdomains) {
      auto space_idx = cpdomain.find(' ');
      auto count = std::stoi(cpdomain.substr(0, space_idx));
      auto last_pos = std::string::npos;
      while (true) {
        auto delimiter_pos = cpdomain.find_last_of(". ", last_pos);
        if (delimiter_pos == std::string::npos) {
          break;
        }
        last_pos = delimiter_pos - 1;
        auto key = cpdomain.substr(delimiter_pos + 1,
                                   cpdomain.size() - delimiter_pos - 1);
        auto it = counts.find(key);
        if (it == counts.end()) {
          counts[key] = count;
        } else {
          it->second += count;
        }
      }
    }
    std::vector<std::string> result;
    result.reserve(counts.size());
    for (const auto &[domain, count] : counts) {
      std::stringstream builder;
      builder << count << " " << domain;
      result.push_back(builder.str());
    }
    return result;
  }
};
