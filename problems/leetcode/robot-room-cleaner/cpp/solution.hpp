#pragma once

#include <array>
#include <utility>

// This is the robot's control interface.
// You should not implement it, or speculate about its implementation
class Robot {
 public:
  // Returns true if the cell in front is open and robot moves into the cell.
  // Returns false if the cell in front is blocked and robot stays in the
  // current cell.
  bool move();

  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
};

static const int kUp = 0, kRight = 1, kDown = 2, kLeft = 3;
static std::array<int, 4> directions{kUp, kRight, kDown, kLeft};

class Solution {
 public:
  void cleanRoom(Robot &robot) { visit(robot, kUp); }

 private:
  void visit(Robot &robot, int return_dir) {
    robot.clean();
    mark(i_, j_);
    for (auto next_dir : directions) {
      auto [next_i, next_j] = nextCell(i_, j_, next_dir);
      if (isVisited(next_i, next_j)) {
        continue;
      }
      faceDirection(robot, next_dir);
      if (!robot.move()) {
        continue;
      }
      i_ = next_i;
      j_ = next_j;
      dir_ = next_dir;
      visit(robot, opposite(dir_));
    }
    faceDirection(robot, return_dir);
    robot.move();
    auto [next_i, next_j] = nextCell(i_, j_, return_dir);
    i_ = next_i;
    j_ = next_j;
  }

  void faceDirection(Robot &robot, int direction) {
    auto diff = direction - dir_;
    if (diff > 2) {
      diff = diff - 4;
    } else if (diff < -2) {
      diff = diff + 4;
    }
    for (; diff > 0; diff--) {
      turnRight(robot);
    }
    for (; diff < 0; diff++) {
      turnLeft(robot);
    }
  }

  inline void turnRight(Robot &robot) {
    robot.turnRight();
    dir_ = (dir_ + 1) % 4;
  }

  inline void turnLeft(Robot &robot) {
    robot.turnLeft();
    dir_ = (dir_ + 3) % 4;
  }

  static inline std::pair<int, int> nextCell(int i, int j, int direction) {
    if (direction == kUp) {
      return {i - 1, j};
    }
    if (direction == kRight) {
      return {i, j + 1};
    }
    if (direction == kDown) {
      return {i + 1, j};
    }
    // kLeft
    return {i, j - 1};
  }

  static inline int opposite(int direction) { return (direction + 2) % 4; }

  inline void mark(int i, int j) { visited_[200 + i][200 + j] = 1; }

  inline bool isVisited(int i, int j) { return visited_[200 + i][200 + j]; }

  int i_;
  int j_;
  int dir_;
  int prev_dir_;
  std::array<std::array<int, 401>, 401> visited_;
};
