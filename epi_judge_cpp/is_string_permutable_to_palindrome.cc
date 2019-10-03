#include <string>
#include <unordered_map>
#include <unordered_set>
#include "test_framework/generic_test.h"
using std::string;
using std::unordered_map;
using std::unordered_set;

bool CanFormPalindrome(const string& s) {

  unordered_set<char> odds;

  for (const auto& c : s) {
    if (odds.find(c) != odds.end())
      odds.erase(c);
    else
      odds.insert(c);
  }

  return odds.size() <= 1;

  // unordered_map<char,int> freq;

  // for (const auto& c : s)
  //   freq[c]++;

  // int odds = 0;
  // for (auto [k,v] : freq) {
  //   if (v % 2 != 0) odds++;
  // }

  // return odds <= 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_permutable_to_palindrome.cc",
                         "is_string_permutable_to_palindrome.tsv",
                         &CanFormPalindrome, DefaultComparator{}, param_names);
}
