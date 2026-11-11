// Difficulty: Medium | Time: O(n) | Space: O(h) | Pattern: Tree | Use: Accumulating values along hierarchical paths (prefix codes)
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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;

        // Append this digit to the number built so far
        current = current * 10 + node->val;

        // A leaf completes one number
        if (!node->left && !node->right) return current;

        return dfs(node->left, current) + dfs(node->right, current);
    }
};
