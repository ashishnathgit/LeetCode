// Difficulty: Medium | Time: O(C(9,k) * k) | Space: O(k) | Pattern: Backtracking | Use: Enumerating constrained subsets in puzzles (e.g. Kakuro)
class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(int start, int k, int n) {
        if ((int)cur.size() == k) {
            if (n == 0) res.push_back(cur);
            return;
        }
        for (int d = start; d <= 9 && d <= n; ++d) {
            cur.push_back(d);
            dfs(d + 1, k, n - d);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return res;
    }
};
