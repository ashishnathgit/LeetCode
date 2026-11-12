// Difficulty: Easy | Time: O(n) | Space: O(h) | Pattern: Binary Tree DFS | Use: Mirroring hierarchical layouts (e.g. RTL UI trees)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
