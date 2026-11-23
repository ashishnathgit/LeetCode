// Difficulty: Hard | Time: O(m · n) | Space: O(m · n) | Pattern: Graph | Use: Longest monotonic paths in terrain elevation and DAG grids
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));

        int best = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                best = max(best, dfs(matrix, memo, r, c, m, n));
            }
        }
        return best;
    }

private:
    int dfs(const vector<vector<int>>& matrix, vector<vector<int>>& memo,
            int r, int c, int m, int n) {
        if (memo[r][c] != 0) return memo[r][c];

        static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int best = 1;
        for (const auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) {
                best = max(best, 1 + dfs(matrix, memo, nr, nc, m, n));
            }
        }
        return memo[r][c] = best;
    }
};
