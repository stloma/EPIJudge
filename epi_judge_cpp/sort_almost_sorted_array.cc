#include <vector>
#include <queue>
#include "test_framework/generic_test.h"
using std::vector;
using std::priority_queue;
vector<int> SortApproximatelySortedData(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end, int k) {

  vector<int> A;
  priority_queue<int> pq;
  while (sequence_begin != sequence_end)
    A.push_back(*sequence_begin++);

  for (int i = 0; i < k; ++i) {
    pq.push(-A[i]);
  }

  int i = 0;
  for (; k < A.size(); ++i) {
    A[i] = -pq.top(); pq.pop();
    pq.push(-A[k++]);
  }

  while (!pq.empty()) {
    A[i++] = -pq.top(); pq.pop();
  }

  return A;
}
vector<int> SortApproximatelySortedDataWrapper(const vector<int>& sequence,
                                               int k) {
  return SortApproximatelySortedData(cbegin(sequence), cend(sequence), k);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence", "k"};
  return GenericTestMain(
      args, "sort_almost_sorted_array.cc", "sort_almost_sorted_array.tsv",
      &SortApproximatelySortedDataWrapper, DefaultComparator{}, param_names);
}
