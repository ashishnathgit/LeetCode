// Difficulty: Medium | Time: O(n log k) | Space: O(k) | Pattern: Heap | Use: Top-K leaderboards and streaming rank queries
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Keep a min-heap of the k largest seen so far; its top is the kth largest.
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : nums) {
            pq.push(x);
            if ((int)pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
