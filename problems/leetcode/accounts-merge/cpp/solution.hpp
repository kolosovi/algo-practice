#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<std::string>> accountsMerge(
      std::vector<std::vector<std::string>> &accounts) {
    std::unordered_map<std::string, std::vector<int>> email_to_indexes;
    std::vector<std::vector<std::string>> result;
    std::unordered_set<int> merged_indexes;
    for (int account_i = 0; account_i < accounts.size(); ++account_i) {
      for (int email_i = 1; email_i < accounts[account_i].size(); ++email_i) {
        email_to_indexes[accounts[account_i][email_i]].push_back(account_i);
      }
    }
    for (int account_i = 0; account_i < accounts.size(); ++account_i) {
      auto merged_it = merged_indexes.find(account_i);
      if (merged_it != merged_indexes.end()) {
        continue;
      }
      auto &account = accounts[account_i];
      int unprocessed_emails_start = 1;
      for (; unprocessed_emails_start < account.size();
           unprocessed_emails_start++) {
        const auto &indexes =
            email_to_indexes[account[unprocessed_emails_start]];
        for (auto index : indexes) {
          if (index == account_i) {
            continue;
          }
          merged_it = merged_indexes.find(index);
          if (merged_it != merged_indexes.end()) {
            continue;
          }
          merged_indexes.insert(index);
          const auto &other_account = accounts[index];
          for (int email_i = 1; email_i < other_account.size(); ++email_i) {
            auto email_it = std::find(account.begin(), account.end(),
                                      other_account[email_i]);
            if (email_it != account.end()) {
              continue;
            }
            account.push_back(other_account[email_i]);
          }
        }
      }
      std::sort(std::next(account.begin()), account.end());
      int w = 0;
      for (int i = 1; i < account.size(); ++i) {
        if (i == 1 || account[i] != account[i - 1]) {
          account[1 + w] = account[i];
          w++;
        }
      }
      account.resize(1 + w);
      result.push_back(std::move(account));
    }
    return result;
  }
};
