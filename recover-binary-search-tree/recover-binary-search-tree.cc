class Solution {
 public:
  void recoverTree(TreeNode* root) {
    vector<int> vals;
    vector<TreeNode*> nodes;

    inorder(root, vals, nodes);
    std::sort(vals.begin(), vals.end());
    for (int i = 0; i < vals.size(); i++) {
      nodes[i]->val = vals[i];
    }
    return;
  }

  void inorder(TreeNode* root, vector<int>& vals, vector<TreeNode*>& nodes) {
    if (root == nullptr) return;
    inorder(root->left, vals, nodes);
    vals.push_back(root->val);
    nodes.push_back(root);
    inorder(root->right, vals, nodes);
  }
};
