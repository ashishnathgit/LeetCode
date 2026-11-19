// Difficulty: Medium | Time: O(n * sqrt(n)) | Space: O(n) | Pattern: Dynamic Programming | Use: Minimum-coin style change making and resource packing
class Solution {
public:
    int numSquares(int n) {
        // dp[i] = fewest perfect squares summing to i
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j * j <= i; ++j)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        return dp[n];
    }
};
