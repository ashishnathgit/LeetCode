// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Dynamic Programming | Use: Scheduling on circular timetables
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // The first and last houses touch, so rob at most one of them:
        // try skipping the last house, then try skipping the first
        return max(robLine(nums, 0, n - 2), robLine(nums, 1, n - 1));
    }

private:
    // House Robber I on nums[start..end]
    int robLine(const vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; ++i) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
