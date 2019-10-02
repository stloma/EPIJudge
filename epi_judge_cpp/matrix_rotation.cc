#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
void RotateMatrix(vector<vector<int>>* square_matrix_ptr) {
  auto& matrix = *square_matrix_ptr;

  std::reverse(matrix.begin(), matrix.end());

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = i + 1; j < matrix[0].size(); ++j) {
      std::swap(matrix[i][j], matrix[j][i]);
    }
  }
}
vector<vector<int>> RotateMatrixWrapper(vector<vector<int>> square_matrix) {
  RotateMatrix(&square_matrix);
  return square_matrix;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"square_matrix"};
  return GenericTestMain(args, "matrix_rotation.cc", "matrix_rotation.tsv",
                         &RotateMatrixWrapper, DefaultComparator{},
                         param_names);
}
