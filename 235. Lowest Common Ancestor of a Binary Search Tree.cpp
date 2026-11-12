// Difficulty: Medium | Time: O(h) | Space: O(1) | Pattern: BST Traversal | Use: Finding shared ancestors in ordered hierarchies
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) root = root->left;
            else if (p->val > root->val && q->val > root->val) root = root->right;
            else return root;
        }
        return nullptr;
    }
};
