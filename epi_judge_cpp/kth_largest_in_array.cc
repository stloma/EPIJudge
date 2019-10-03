#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int find_idx(vector<int>& A, int l, int r) {

  // Take median of three
  int right = A[r];
  int left = A[l];
  int m = A[(r+l)/ 2];

  auto tmp = vector<int> {right, left, m};
  std::sort(tmp.begin(), tmp.end());
  int pivot = tmp[1];

  if (pivot == left) std::swap(A[r], A[l]);
  else if (pivot == m) std::swap(A[r], A[(r+l)/ 2]);

  int j = l - 1;
  for (; l < r; ++l) {
    if (A[l] <= pivot)
      std::swap(A[++j], A[l]);
  }

  std::swap(A[++j], A[r]);

  return j;
}

// The numbering starts from one, i.e., if A = [3, 1, -1, 2] then
// FindKthLargest(1, A) returns 3, FindKthLargest(2, A) returns 2,
// FindKthLargest(3, A) returns 1, and FindKthLargest(4, A) returns -1.
int FindKthLargest(int k, vector<int>* A_ptr) {
  auto& A = *A_ptr;

  int l = 0, r = A.size()-1, idx = A.size()-k;

  while (l <= r) {
    auto result = find_idx(A, l, r);
    if (result == idx) return A[result];

    if (result < idx) l = result + 1;
    else r = result - 1;
  }

  return 0;
}
int FindKthLargestWrapper(int k, vector<int>& A) {
  return FindKthLargest(k, &A);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k", "A"};
  return GenericTestMain(args, "kth_largest_in_array.cc",
                         "kth_largest_in_array.tsv", &FindKthLargestWrapper,
                         DefaultComparator{}, param_names);
}
