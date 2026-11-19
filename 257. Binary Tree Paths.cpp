// Difficulty: Easy | Time: O(n * h) | Space: O(h) | Pattern: Tree | Use: Listing every full path in a file system or category tree
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root) dfs(root, "", paths);
        return paths;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        path += to_string(node->val);

        // Leaf: the path is complete
        if (!node->left && !node->right) {
            paths.push_back(path);
            return;
        }
        path += "->";
        if (node->left) dfs(node->left, path, paths);
        if (node->right) dfs(node->right, path, paths);
    }
};
