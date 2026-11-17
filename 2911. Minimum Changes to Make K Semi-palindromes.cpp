// Difficulty: Hard | Time: O(n^3 * log n + n^2 * k) | Space: O(n^2) | Pattern: Interval Cost Precompute + Partition DP | Use: Splitting sequences into segments with per-segment repair cost
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        // cost[i][j]: min changes to make s[i..j] a semi-palindrome.
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                for (int d = 1; d < len; d++) {
                    if (len % d) continue;
                    int changes = 0;
                    // Each residue class mod d must form a palindrome.
                    for (int r = 0; r < d; r++) {
                        int lo = i + r, hi = j - (d - 1 - r);
                        while (lo < hi) {
                            if (s[lo] != s[hi]) changes++;
                            lo += d;
                            hi -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        // dp[i][p]: min changes to split s[0..i-1] into p semi-palindromes.
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 2; i <= n; i++)
            for (int p = 1; p <= k; p++)
                for (int j = 2 * (p - 1); j <= i - 2; j++)
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j][i - 1]);
        return dp[n][k];
    }
};
