/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  void pathSum2(TreeNode* node, int sum, int targetSum, vector<int> vec) {
    sum += node->val;
    vec.push_back(node->val);
    if (!node->left && !node->right) {
      if (sum == targetSum) {
        ans.push_back(vec);
      }
      return;
    }
    if (node->left) {
      pathSum2(node->left, sum, targetSum, vec);
    }
    if (node->right) {
      pathSum2(node->right, sum, targetSum, vec);
    }
  }
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    if (!root) {
      return ans;
    }
    vector<int> vec;
    pathSum2(root, sum, targetSum, vec);
    return ans;
  }

 private:
  vector<vector<int>> ans;
};