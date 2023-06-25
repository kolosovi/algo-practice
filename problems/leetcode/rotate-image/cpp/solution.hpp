class Solution {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int diagonal = 0; diagonal < n; diagonal++) {
      for (int i = diagonal + 1; i < n; i++) {
        std::swap(matrix[i][diagonal], matrix[diagonal][i]);
      }
    }
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < n / 2; col++) {
        std::swap(matrix[row][col], matrix[row][n - col - 1]);
      }
    }
  }
};
