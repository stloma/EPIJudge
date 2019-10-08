#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {

  auto dummy = make_shared<ListNode<int>> (0);
  dummy->next = L;
  auto left = dummy;

  for (int i = 1; i < start; ++i)
    left = left->next;

  for (auto iter = left->next; start < finish; ++start) {
    auto tmp = iter->next;
    iter->next = tmp->next;
    tmp->next = left->next;
    left->next = tmp;
  }

  return dummy->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
