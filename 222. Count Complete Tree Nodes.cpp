// Difficulty: Easy | Time: O(log^2 n) | Space: O(log n) | Pattern: Binary Tree + Divide and Conquer | Use: Sizing heap-shaped trees without full traversal
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = 0, rh = 0;
        for (TreeNode* n = root; n; n = n->left) lh++;
        for (TreeNode* n = root; n; n = n->right) rh++;
        // Perfect tree: count directly.
        if (lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
