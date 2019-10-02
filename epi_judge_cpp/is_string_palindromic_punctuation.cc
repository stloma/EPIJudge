#include <string>
#include "test_framework/generic_test.h"
using std::string;

bool IsPalindrome(const string& s) {

  int i = 0, j = s.size() - 1;

  while (i < j) {
    while (i < j && !isalnum(s[i])) i++;
    while (j > i && !isalnum(s[j])) j--;

    if (i < j) {
      if (tolower(s[i++]) != tolower(s[j--])) return false;
    }
  }

  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_palindromic_punctuation.cc",
                         "is_string_palindromic_punctuation.tsv", &IsPalindrome,
                         DefaultComparator{}, param_names);
}
