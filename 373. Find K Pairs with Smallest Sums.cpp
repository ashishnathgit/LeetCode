// Difficulty: Medium | Time: O(k log(min(n, k))) | Space: O(min(n, k)) | Pattern: Heap | Use: Top-k Cartesian sum retrieval in ranking and pricing combinations
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using Entry = tuple<int, int, int>;  // {sum, i, j}
        priority_queue<Entry, vector<Entry>, greater<Entry>> minHeap;

        int limit = min((int)nums1.size(), k);
        for (int i = 0; i < limit; ++i) {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }

        vector<vector<int>> result;
        result.reserve(k);
        while (!minHeap.empty() && (int)result.size() < k) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < (int)nums2.size()) {
                minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }
        return result;
    }
};
