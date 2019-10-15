#include <string>
#include <vector>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;

int LevenshteinDistance(const string& A, const string& B) {

  vector<vector<int>> dp (A.size()+1, vector<int> (B.size()+1));

  for (int i = 0; i <= A.size(); ++i)
    dp[i][0] = i;
  for (int i = 0; i <= B.size(); ++i)
    dp[0][i] = i;

  for (int i = 1; i <= A.size(); ++i) {
    for (int j = 1; j <= B.size(); ++j) {
      if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1])) + 1;
    }
  }

  return dp[A.size()][B.size()];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, "levenshtein_distance.cc",
                         "levenshtein_distance.tsv", &LevenshteinDistance,
                         DefaultComparator{}, param_names);
}
