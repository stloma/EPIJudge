#include <iterator>
#include <string>
#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::string;
using std::vector;

int ReplaceAndRemove(int size, char s[]) {

  int a_cnt = 0;
  int w_idx = 0;
  for (int i = 0; i < size; ++i) {
    if (s[i] != 'b')
      s[w_idx++] = s[i];
    if (s[i] == 'a')
      a_cnt++;
  }

  int right = a_cnt + w_idx - 1;
  int left = w_idx - 1;
  const int result = right + 1;

  while (left >= 0) {
    if (s[left] == 'a') {
      s[right--] = 'd';
      s[right--] = 'd';
    } else
      s[right--] = s[left];
    left--;
  }

  return result;
}
vector<string> ReplaceAndRemoveWrapper(TimedExecutor& executor, int size,
                                       const vector<string>& s) {
  std::vector<char> s_copy(s.size(), '\0');
  for (int i = 0; i < s.size(); ++i) {
    if (!s[i].empty()) {
      s_copy[i] = s[i][0];
    }
  }

  int res_size =
      executor.Run([&] { return ReplaceAndRemove(size, s_copy.data()); });

  vector<string> result;
  for (int i = 0; i < res_size; ++i) {
    result.emplace_back(string(1, s_copy[i]));
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "size", "s"};
  return GenericTestMain(args, "replace_and_remove.cc",
                         "replace_and_remove.tsv", &ReplaceAndRemoveWrapper,
                         DefaultComparator{}, param_names);
}
