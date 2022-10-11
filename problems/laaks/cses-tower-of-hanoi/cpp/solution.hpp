#pragma once

#include <array>
#include <istream>
#include <ostream>

static constexpr int kL = 1;
static constexpr int kM = 2;
static constexpr int kR = 3;

void solve(std::ostream &out, std::array<int, 3> map, int n) {
  if (n == 0) {
    return;
  }
  solve(out, {map[kL - 1], map[kR - 1], map[kM - 1]}, n - 1);
  out << map[kL - 1] << ' ' << map[kR - 1] << '\n';
  solve(out, {map[kM - 1], map[kL - 1], map[kR - 1]}, n - 1);
}

void Solve(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  out << ((1 << n) - 1) << '\n';
  solve(out, {kL, kM, kR}, n);
}
