#include <string>
#include <unordered_set>
#include "test_framework/generic_test.h"
using std::string;
using std::unordered_set;

// Uses BFS to find the least steps of transformation.
int TransformString(unordered_set<string> D, const string& s, const string& t) {

  if (s == t) return 0;

  struct StringWithDepth {
      string s;
      int depth;
  };

  std::queue<StringWithDepth> q;
  q.push({s, 0});
  D.erase(s);

  while (!q.empty()) {
    auto u = q.front(); q.pop();

    if (u.s == t) return u.depth;

    auto tmp_s = u.s;
    for (int i = 0; i < s.size(); ++i) {
      for (int c = 0; c < 26; ++c) {
        tmp_s[i] = c + 'a';
        if (D.find(tmp_s) != D.end()) {
          q.push({tmp_s, u.depth + 1});
          D.erase(tmp_s);
        }
      }
      tmp_s[i] = u.s[i];
    }
  }

  return -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"D", "s", "t"};
  return GenericTestMain(args, "string_transformability.cc",
                         "string_transformability.tsv", &TransformString,
                         DefaultComparator{}, param_names);
}
