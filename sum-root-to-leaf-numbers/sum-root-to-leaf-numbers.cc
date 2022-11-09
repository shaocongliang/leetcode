class Solution {
 public:
  void extractNumber(TreeNode *node, int prev) {
    prev = prev * 10 + node->val;
    if (!node->left && !node->right) {
      nums.push_back(prev);
      return;
    }
    if (node->left) extractNumber(node->left, prev);
    if (node->right) extractNumber(node->right, prev);
  }
  int sumNumbers(TreeNode *root) {
    if (!root) {
      return 0;
    }
    extractNumber(root, 0);
    return std::accumulate(nums.begin(), nums.end(), 0);
  }

 private:
  vector<int> nums;
};