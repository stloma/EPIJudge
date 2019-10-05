#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
void ApplyPermutation(vector<int>* perm_ptr, vector<int>* A_ptr) {
  auto& P = *perm_ptr;
  auto& A = *A_ptr;

  for (int i = 0; i < A.size(); ++i) {

    int n = A[i];
    while (P[i] != -1) {
      std::swap(n, A[P[i]]);

      int tmp = P[i];
      P[i] = -1;
      i = tmp;
    }
  }

  return;
}
vector<int> ApplyPermutationWrapper(vector<int> perm, vector<int> A) {
  ApplyPermutation(&perm, &A);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm", "A"};
  return GenericTestMain(args, "apply_permutation.cc", "apply_permutation.tsv",
                         &ApplyPermutationWrapper, DefaultComparator{},
                         param_names);
}
