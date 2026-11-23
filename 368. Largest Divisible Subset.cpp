// Difficulty: Medium | Time: O(n²) | Space: O(n) | Pattern: Dynamic Programming | Use: Longest chain reconstruction over transitive divisibility DAGs
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), parent(n, -1);

        int bestIdx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[bestIdx]) bestIdx = i;
        }

        vector<int> subset;
        for (int cur = bestIdx; cur != -1; cur = parent[cur]) {
            subset.push_back(nums[cur]);
        }
        reverse(subset.begin(), subset.end());
        return subset;
    }
};
