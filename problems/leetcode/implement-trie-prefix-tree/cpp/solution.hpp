#pragma once

#include <string>
#include <unordered_map>

struct SearchResult {
    bool is_found;
    bool is_terminal_match;
};

class Trie {
public:
    Trie() {
    }

    void insert(std::string word) {
        auto node = this;
        for (int i = 0; i < word.size(); ++i) {
            Trie *next_node;
            auto next_node_it = node->children_.find(word[i]);
            if (next_node_it != node->children_.end()) {
                next_node = next_node_it->second;
            } else {
                next_node = new Trie();
                node->children_[word[i]] = next_node;
            }
            if (i == word.size() - 1) {
                node->map_is_terminal_[word[i]] = true;
            }
            node = next_node;
        }
    }

    bool search(std::string word) {
        auto search_result = searchAnyMatch(word);
        return search_result.is_found && search_result.is_terminal_match;
    }

    bool startsWith(std::string prefix) {
        auto search_result = searchAnyMatch(prefix);
        return search_result.is_found;
    }

private:
    std::unordered_map<char, Trie*> children_;
    std::unordered_map<char, bool> map_is_terminal_;

    SearchResult searchAnyMatch(std::string word) {
        bool is_terminal_match = false;
        auto node = this;
        for (int i = 0; i < word.size() && node != nullptr; ++i) {
            auto child_it = node->children_.find(word[i]);
            if (child_it == node->children_.end()) {
                return {false, false};
            }
            if (i == word.size() - 1 && node->map_is_terminal_[word[i]]) {
                is_terminal_match = true;
            }
            node = child_it->second;
        }
        return {true, is_terminal_match};
    }
};
