// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Sliding Window | Use: Shortest window that meets a quota (rate limits, SLAs)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, best = INT_MAX;

        // Sliding window: grow on the right, shrink from the left while the sum is enough
        for (int right = 0; right < (int)nums.size(); ++right) {
            sum += nums[right];
            while (sum >= target) {
                best = min(best, right - left + 1);
                sum -= nums[left++];
            }
        }
        return best == INT_MAX ? 0 : best;
    }
};
