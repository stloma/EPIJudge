#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

void permute(int pos, vector<int>& A, vector<vector<int>>& result) {
  if (pos == A.size())
    result.push_back(A);

  else {
    for (int i = pos; i < A.size(); ++i) {
      std::swap(A[i], A[pos]);
      permute(pos+1, A, result);
      std::swap(A[i], A[pos]);
    }
  }
}

vector<vector<int>> Permutations(vector<int> A) {
  vector<vector<int>> result;

  permute(0, A, result);

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(
      args, "permutations.cc", "permutations.tsv", &Permutations,
      &UnorderedComparator<vector<vector<int>>>, param_names);
}
