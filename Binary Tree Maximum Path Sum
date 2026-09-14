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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        calculateMaxGain(root, maxSum);
        return maxSum;
    }

private:
    int calculateMaxGain(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // Recursively compute the maximum gain from the left and right subtrees.
        // Ignore paths that yield a negative sum by clamping to 0.
        int leftGain = max(0, calculateMaxGain(node->left, maxSum));
        int rightGain = max(0, calculateMaxGain(node->right, maxSum));

        // Calculate the maximum path sum where the current node acts as the highest apex.
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the global maximum if the current local path is larger.
        maxSum = max(maxSum, currentPathSum);

        // Return the maximum gain the parent node can get by extending down this branch.
        return node->val + max(leftGain, rightGain);
    }
};
