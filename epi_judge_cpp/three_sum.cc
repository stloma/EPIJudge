#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

bool HasThreeSum(vector<int> A, int t) {

  // 143 us average, 5 us median
  std::sort(A.begin(), A.end());

  for (int i = 0; i < A.size(); ++i) {
    int l = i, r = A.size() - 1;
    int target = t - A[i];

    while (l <= r) {
      int left = A[l];
      int right = A[r];
      int sum = left + right;

      if (sum == target) return true;
      if (sum < target) l++;
      else r--;
    }
  }

  // 333 us average, 3 us median
  // for (auto a : A) {
  //   for (auto b : A) {
  //     for (auto c : A) {
  //       if (a + b + c == t) return true;
  //     }
  //   }
  // }

  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "three_sum.cc", "three_sum.tsv", &HasThreeSum,
                         DefaultComparator{}, param_names);
}
