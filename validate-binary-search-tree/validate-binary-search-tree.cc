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
    bool isValidBST(TreeNode* root) {
        inOrderBrowser(root);
        return std::is_sorted(ans.begin(), ans.end(), [](const int lhs, const int rhs) {
            return lhs <= rhs;
        });
    }
    void inOrderBrowser(TreeNode *node) {
        if(!node) {
            return;
        }
        inOrderBrowser(node->left);
        ans.push_back(node->val);
        inOrderBrowser(node->right);
    }
private:
    vector<int> ans;
};
