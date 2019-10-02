#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {

  auto dummy_head = std::make_shared<ListNode<int>> (0);
  auto curr = dummy_head;

  while (L1 && L2) {
    if (L1->data < L2->data) {
      curr->next = L1;
      L1 = L1->next;
    } else {
      curr->next = L2;
      L2 = L2->next;
    }
    curr = curr->next;
  }

  if (L1) curr->next = L1;
  if (L2) curr->next = L2;

  return dummy_head->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}
