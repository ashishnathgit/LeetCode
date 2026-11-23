// Difficulty: Hard | Time: O(n³) | Space: O(n²) | Pattern: Dynamic Programming | Use: Optimal matrix-chain and interval elimination ordering
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; ++i) a[i + 1] = nums[i];

        // dp[l][r] = max coins from bursting all balloons strictly inside (l, r)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 2; len < n + 2; ++len) {
            for (int l = 0; l + len < n + 2; ++l) {
                int r = l + len;
                for (int k = l + 1; k < r; ++k) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
