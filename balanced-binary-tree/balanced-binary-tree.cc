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
    int height(TreeNode* node) {
        if (!node)
            return 0;
        int l = 0, r = 0;
        if (node->left) {
            l = height(node->left);
            if (l == -1)
                return -1;
            else
                l += 1;
        }
        if (node->right) {
            r = height(node->right);
            if (r == -1)
                return -1;
            else
                r += 1;
        }
        if (std::abs(l - r) > 1)
            return -1;
        else
            return std::max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) == -1 ? false : true;
    }
};
