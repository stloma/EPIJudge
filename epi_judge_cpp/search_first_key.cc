#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

int SearchFirstOfK(const vector<int>& A, int k) {

  int l = 0, r = A.size()-1, result = -1;

  while (l <= r) {

    int m = l + (r - l) / 2;

    if (k <= A[m]) {
      if (A[m] == k) result = m;
      r = m - 1;
    } else
      l = m + 1;

  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}
