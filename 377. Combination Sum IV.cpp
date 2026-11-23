// Difficulty: Medium | Time: O(target · n) | Space: O(target) | Pattern: Dynamic Programming | Use: Counting ordered step permutations that sum to a budget
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = 1; t <= target; ++t) {
            for (int x : nums) {
                if (x <= t) dp[t] += dp[t - x];
            }
        }
        return static_cast<int>(dp[target]);
    }
};
