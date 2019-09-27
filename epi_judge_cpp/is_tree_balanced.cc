#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

int height(const unique_ptr<BinaryTreeNode<int>>& tree) {

  if (!tree) return 0;

  return std::max(height(tree->left), height(tree->right)) + 1;

}

int check_balanced(const unique_ptr<BinaryTreeNode<int>>& tree) {

  if (!tree) return 0;

  auto left = check_balanced(tree->left);
  auto right = check_balanced(tree->right);

  if (abs(left - right) > 1 || left == -1 || right == -1) return -1;

  return std::max(left, right) + 1;

}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {

  if (!tree) return true;

  return check_balanced(tree) != -1;

  // if (!tree) return true;

  // auto left = height(tree->left);
  // auto right = height(tree->right);

  // return abs(left - right) <= 1 && IsBalanced(tree->left) && IsBalanced(tree->right);

}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
