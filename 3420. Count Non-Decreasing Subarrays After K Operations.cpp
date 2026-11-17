// Difficulty: Hard | Time: O(n) | Space: O(n) | Pattern: Sliding Window + Monotonic Deque | Use: Counting ranges whose "raise to running max" cost fits a budget
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, cost = 0;
        // Window [i, j], sweeping i right-to-left. dq holds the prefix-max
        // "leaders" of the window (values strictly increasing front to back);
        // each leader owns the segment up to the next leader, raised to its value.
        deque<int> dq;
        int j = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            // nums[i] absorbs every leader it dominates, raising their segments.
            while (!dq.empty() && nums[dq.front()] <= nums[i]) {
                int t = dq.front();
                dq.pop_front();
                int end = dq.empty() ? j + 1 : dq.front();
                cost += (long long)(nums[i] - nums[t]) * (end - t);
            }
            dq.push_front(i);
            // Shrink from the right until the window fits the budget.
            while (cost > k) {
                cost -= nums[dq.back()] - nums[j];
                if (dq.back() == j) dq.pop_back();
                j--;
            }
            ans += j - i + 1;
        }
        return ans;
    }
};
