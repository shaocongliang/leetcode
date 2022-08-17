/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
     findKthSmallest(root);
     return ans[k-1];
    }
    void findKthSmallest(TreeNode* node) {
      if(node == nullptr) {
        return;
      }
      findKthSmallest(node->left);
      ans.push_back(node->val);
      findKthSmallest(node->right);
    }
private:
  vector<int> ans;
};
