#include <string>
#include "test_framework/generic_test.h"
using std::string;

// Returns the index of the first character of the substring if found, -1
// otherwise.
int RabinKarp(const string &t, const string &s) {
  if (s.empty()) return 0;
  if (s.size() > t.size()) return -1;

  for (int i = 0; i < t.size(); ++i) {
    int j = 0, k = i;
    while (j < s.size() && t[k] == s[j]) {
      j++;
      k++;
    }
    if (j == s.size()) return i;
  }

  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"t", "s"};
  return GenericTestMain(args, "substring_match.cc", "substring_match.tsv",
                         &RabinKarp, DefaultComparator{}, param_names);
}
