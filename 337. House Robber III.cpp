// Difficulty: Medium | Time: O(n) | Space: O(h) | Pattern: Tree | Use: Independent-set profit optimization on hierarchical org or resource trees
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
    int rob(TreeNode* root) {
        auto [skip, take] = dfs(root);
        return max(skip, take);
    }

private:
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int skip = max(left.first, left.second) + max(right.first, right.second);
        int take = node->val + left.first + right.first;
        return {skip, take};
    }
};
