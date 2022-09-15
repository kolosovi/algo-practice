#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
 public:
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>> &prerequisites) {
    std::vector<int> empty;
    std::vector<std::vector<int>> prereq_to_courses(
        static_cast<std::vector<int>::size_type>(numCourses), empty);
    std::vector<int> course_to_prereq_count(
        static_cast<std::vector<int>::size_type>(numCourses), 0);
    for (const auto &req : prerequisites) {
      prereq_to_courses[req[1]].emplace_back(req[0]);
      course_to_prereq_count[req[0]]++;
    }
    std::unordered_map<int, std::unordered_set<int>> degree_to_courses;
    for (int course = 0; course < course_to_prereq_count.size(); course++) {
      degree_to_courses[course_to_prereq_count[course]].insert(course);
    }
    std::vector<int> result;
    while (degree_to_courses[0].size() > 0) {
      auto next_course_it = degree_to_courses[0].begin();
      auto next_course = *next_course_it;
      result.emplace_back(next_course);
      degree_to_courses[0].erase(next_course_it);
      for (auto dependee : prereq_to_courses[next_course]) {
        auto &dependee_degree = course_to_prereq_count[dependee];
        degree_to_courses[dependee_degree].erase(dependee);
        dependee_degree--;
        degree_to_courses[dependee_degree].insert(dependee);
      }
    }
    if (result.size() != numCourses) {
      return {};
    }
    return result;
  }
};
