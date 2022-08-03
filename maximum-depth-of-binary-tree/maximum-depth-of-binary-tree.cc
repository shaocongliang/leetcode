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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int leftH = 0;
        int rightH = 0;
        if(root->left != nullptr) {
            leftH = maxDepth(root->left) + 1;
        }
        if (root->right != nullptr) {
            rightH = maxDepth(root->right) + 1;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        return max(leftH, rightH);
    }
};
