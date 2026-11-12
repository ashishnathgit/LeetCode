// Difficulty: Hard | Time: O(n) | Space: O(k) | Pattern: Monotonic Deque | Use: Rolling max for stock prices and network monitoring
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Deque holds indices with strictly decreasing values; front is the window max.
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
