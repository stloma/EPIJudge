#include <vector>
#include <algorithm>
#include "test_framework/generic_test.h"
using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {

  if (A.empty() || B.empty()) return {};

  vector<int> result;
  int a = 0, b = 0;

  // Average: 9 us, median: 1 us
  while (a < A.size() && b < B.size()) {
    if (A[a] == B[b]) {
      if (result.empty()) result.push_back(A[a]);
      else if (result.back() != A[a]) result.push_back(A[a]);
      a++; b++;
    } else if (A[a] < B[b])
      a++;
    else
      b++;
  }

  // Average: 47 us, median: 2 us
  // for (int i = 0; i < A.size(); i++) {
  //   if (i > 0 && A[i] == A[i-1]) continue;
  //   if (std::binary_search(B.begin(), B.end(), A[i]))
  //     result.push_back(A[i]);
  // }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}
