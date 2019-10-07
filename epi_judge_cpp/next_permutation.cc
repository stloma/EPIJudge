#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
vector<int> NextPermutation(vector<int> perm) {

  // Find first non-decreasing element from back
  int j = perm.size()-2;
  while (j >= 0 && perm[j] >= perm[j+1]) j--;

  // At last permutation
  if (j < 0) return {};

  // Find next smallest element
  auto i = j + 1;
  while (i < perm.size() && perm[i] > perm[j]) i++;

  std::swap(perm[i - 1], perm[j]);

  // Reverse rest of permutation
  i = perm.size();
  while (++j < i--) std::swap(perm[j], perm[i]);

  return perm;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm"};
  return GenericTestMain(args, "next_permutation.cc", "next_permutation.tsv",
                         &NextPermutation, DefaultComparator{}, param_names);
}
