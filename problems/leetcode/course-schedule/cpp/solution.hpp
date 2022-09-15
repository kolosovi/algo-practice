#pragma once

#include <vector>

class Solution {
 public:
  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector<int> empty;
    std::vector<std::vector<int>> dependees(numCourses + 1, empty);
    for (const auto &prerequisite_pair : prerequisites) {
      dependees[prerequisite_pair[1]].emplace_back(prerequisite_pair[0]);
    }
    std::vector<int> visited_courses(numCourses + 1, 0);
    std::vector<int> path(numCourses + 1, 0);
    for (int course = 0; course < numCourses; course++) {
      if (!canFinish(path, visited_courses, dependees, course)) {
        return false;
      }
    }
    return true;
  }

 private:
  bool canFinish(std::vector<int> &path, std::vector<int> &visited_courses,
                 std::vector<std::vector<int>> &dependees, int course) {
    path[course] = 1;
    for (auto dependee : dependees[course]) {
      if (path[dependee] > 0) {
        return false;
      }
      if (visited_courses[dependee] > 0) {
        continue;
      }
      if (!canFinish(path, visited_courses, dependees, dependee)) {
        return false;
      }
    }
    visited_courses[course] = 1;
    path[course] = 0;
    return true;
  }
};
