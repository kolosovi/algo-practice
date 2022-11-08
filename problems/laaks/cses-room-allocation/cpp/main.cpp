// This code was generated, do not edit.

#include <iostream>

#include <algorithm>
#include <istream>
#include <ostream>
#include <vector>

void Solve(std::istream &in, std::ostream &out) {
  int num_customers, num_rooms = 0;
  in >> num_customers;
  std::vector<std::pair<int, int>> edges;
  edges.reserve(2 * num_customers);
  std::vector<int> rooms(num_customers, 0);
  std::vector<int> vacant;
  for (int customer = 0; customer < num_customers; ++customer) {
    int start, end;
    in >> start >> end;
    edges.emplace_back(start, customer);
    edges.emplace_back(-end, customer);
  }
  std::sort(edges.begin(), edges.end(),
            [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
              if (std::abs(lhs.first) == std::abs(rhs.first)) {
                // put opening edges first
                if (lhs.first > 0 && rhs.first < 0) {
                  return true;
                }
                return false;
              }
              return std::abs(lhs.first) < std::abs(rhs.first);
            });
  for (auto [time, customer] : edges) {
    if (time < 0) {
      vacant.emplace_back(rooms[customer]);
    } else {
      if (vacant.size() > 0) {
        rooms[customer] = vacant.back();
        vacant.pop_back();
      } else {
        rooms[customer] = ++num_rooms;
      }
    }
  }
  out << num_rooms << '\n';
  for (int customer = 0; customer < num_customers; ++customer) {
    out << rooms[customer];
    if (customer < num_customers - 1) {
      out << ' ';
    }
  }
  out << '\n';
}

int main() { Solve(std::cin, std::cout); }
