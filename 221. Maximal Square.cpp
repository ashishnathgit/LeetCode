// Difficulty: Medium | Time: O(m*n) | Space: O(n) | Pattern: 2D DP | Use: Finding largest free square region in image/grid maps
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), best = 0;
        // dp[j] = side of largest square ending at (i, j); diag holds dp[i-1][j-1].
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; ++i) {
            int diag = 0;
            for (int j = 1; j <= n; ++j) {
                int tmp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min({dp[j], dp[j - 1], diag}) + 1;
                    best = max(best, dp[j]);
                } else {
                    dp[j] = 0;
                }
                diag = tmp;
            }
        }
        return best * best;
    }
};
