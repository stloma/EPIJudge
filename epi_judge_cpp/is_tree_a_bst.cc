#include <memory>
#include <climits>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;

bool check_range(const unique_ptr<BinaryTreeNode<int>>& tree, int min_value, int max_value) {

  if (!tree) return true;
  if (tree->data < min_value || tree->data > max_value) return false;

  return check_range(tree->left, min_value, tree->data) &&
          check_range(tree->right, tree->data, max_value);
}

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {

  return check_range(tree, INT_MIN, INT_MAX);

}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_a_bst.cc", "is_tree_a_bst.tsv",
                         &IsBinaryTreeBST, DefaultComparator{}, param_names);
}
