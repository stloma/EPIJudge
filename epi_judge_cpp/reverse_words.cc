#include <string>
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::string;

void ReverseWords(string* s) {

  auto& S = *s;

  std::reverse(S.begin(), S.end());

  int r_idx = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == ' ') {
      std::reverse(S.begin() + r_idx, S.begin() + i);
      r_idx = i + 1;
    }
  }
  std::reverse(S.begin() + r_idx, S.end());

  return;
}
string ReverseWordsWrapper(TimedExecutor& executor, string s) {
  string s_copy = s;

  executor.Run([&] { ReverseWords(&s_copy); });

  return s_copy;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "s"};
  return GenericTestMain(args, "reverse_words.cc", "reverse_words.tsv",
                         &ReverseWordsWrapper, DefaultComparator{},
                         param_names);
}
