class Solution {
 public:
  /*
  | A | > |   | B |
  |   |   |   | v |
  | ^ |   |   |   |
  | D |   | < | C |
  */
  void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int first = 0, last = n - 1;
    while (first < last) {
      int A = first, B = first, C = last, D = last;
      for (int i = 0; i < last - first; i++) {
        auto dummy = matrix[first][A];
        matrix[first][A] = matrix[D][first];
        matrix[D][first] = matrix[last][C];
        matrix[last][C] = matrix[B][last];
        matrix[B][last] = dummy;
        A++;
        B++;
        C--;
        D--;
      }
      first++;
      last--;
    }
  }
};
