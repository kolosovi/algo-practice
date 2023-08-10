#pragma once

#include <vector>
#include <algorithm>

class Solution {
 public:
  int maxDistToClosest(std::vector<int>& seats) {
    int last_seat = -1, max = 0, size = seats.size();
    for (int seat = 0; seat <= size; seat++) {
      if (seat == size) {
        max = std::max(max, size - 1 - last_seat);
      } else if (seats[seat]) {
        if (last_seat == -1) {
          max = std::max(max, seat);
        } else {
          max = std::max(max, (seat - last_seat) / 2);
        }
        last_seat = seat;
      }
    }
    return max;
  }
};
