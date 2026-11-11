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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        TreeNode* parentRight = nullptr;

        // Walk down the left spine, flipping each node as we go:
        // the old parent becomes the right child, the old sibling becomes the left child
        while (current) {
            TreeNode* left = current->left;
            TreeNode* right = current->right;

            current->left = parentRight;
            current->right = parent;

            parentRight = right;
            parent = current;
            current = left;
        }
        return parent;  // The old leftmost node is the new root
    }
};
