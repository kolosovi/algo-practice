#pragma once

#include <string>

class Matcher {
 public:
  virtual bool MatchesAt(int i) = 0;
  virtual ~Matcher() = default;
};

class LiteralMatcher : public Matcher {
 public:
  LiteralMatcher(const std::string &s, char lit, Matcher *next)
      : s_(s), lit_(lit), next_(next) {}
  bool MatchesAt(int i) {
    if (i >= s_.size()) {
      return false;
    }
    if (s_[i] != lit_) {
      return false;
    }
    if (next_ == nullptr) {
      if (i == s_.size() - 1) {
        return true;
      }
      return false;
    }
    return next_->MatchesAt(i + 1);
  }

 private:
  const std::string &s_;
  Matcher *next_;
  char lit_;
};

class AlwaysMatcher : public Matcher {
 public:
  bool MatchesAt(int i) { return true; }
};

class AlwaysLiteralMatcher : public Matcher {
 public:
  AlwaysLiteralMatcher(const std::string &s, char lit) : s_(s), lit_(lit) {}
  bool MatchesAt(int i) {
    if (i >= s_.size()) {
      return false;
    }
    return s_[i] == lit_;
  }

 private:
  const std::string &s_;
  char lit_;
};

class DotMatcher : public Matcher {
 public:
  DotMatcher(const std::string &s, Matcher *next) : s_(s), next_(next) {}
  bool MatchesAt(int i) {
    if (i >= s_.size()) {
      return false;
    }
    if (next_ == nullptr) {
      if (i == s_.size() - 1) {
        return true;
      }
      return false;
    }
    return next_->MatchesAt(i + 1);
  }

 private:
  const std::string &s_;
  Matcher *next_;
};

class StarMatcher : public Matcher {
 public:
  StarMatcher(const std::string &s, Matcher *matcher, Matcher *next)
      : s_(s), matcher_(matcher), next_(next) {}
  bool MatchesAt(int i) {
    int j = i;
    for (; j < s_.size(); j++) {
      if (!matcher_->MatchesAt(j)) {
        break;
      }
    }
    if (next_ == nullptr) {
      if (j == s_.size()) {
        return true;
      }
      return false;
    }
    for (int next_start = j; next_start >= i; --next_start) {
      if (next_->MatchesAt(next_start)) {
        return true;
      }
    }
    return false;
  }

 private:
  const std::string &s_;
  Matcher *matcher_;
  Matcher *next_;
};

enum class State { kFree = 0, kStar = 1 };

static constexpr char kStar = '*';
static constexpr char kDot = '.';

class Solution {
 public:
  bool isMatch(std::string s, std::string p) {
    Matcher *next = nullptr;
    State state = State::kFree;
    for (int j = p.size() - 1; j >= 0; j--) {
      if (state == State::kFree) {
        if (p[j] == kStar) {
          state = State::kStar;
          continue;
        }
        if (p[j] == kDot) {
          next = new DotMatcher(s, next);
          continue;
        }
        next = new LiteralMatcher(s, p[j], next);
      } else {
        if (p[j] == kDot) {
          next = new StarMatcher(s, new AlwaysMatcher(), next);
        } else {
          next = new StarMatcher(s, new AlwaysLiteralMatcher(s, p[j]), next);
        }
        state = State::kFree;
      }
    }
    return next->MatchesAt(0);
  }
};
