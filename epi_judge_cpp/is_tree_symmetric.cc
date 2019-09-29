#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

bool symmetry(const unique_ptr<BinaryTreeNode<int>>& l, const unique_ptr<BinaryTreeNode<int>>& r) {
  if (!l && !r) return true;

  if (l && r && l->data == r->data)
    return symmetry(l->left, r->right) && symmetry(l->right, r->left);

  return false;
}

bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
  if (!tree) return true;

  return symmetry(tree->left, tree->right);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_symmetric.cc", "is_tree_symmetric.tsv",
                         &IsSymmetric, DefaultComparator{}, param_names);
}
