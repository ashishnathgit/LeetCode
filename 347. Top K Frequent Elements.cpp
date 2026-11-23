// Difficulty: Medium | Time: O(n) | Space: O(n) | Pattern: Hash Map | Use: Linear-time heavy-hitter extraction via frequency buckets
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) ++freq[x];

        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& [val, count] : freq) {
            buckets[count].push_back(val);
        }

        vector<int> result;
        result.reserve(k);
        for (int c = (int)buckets.size() - 1; c >= 0 && (int)result.size() < k; --c) {
            for (int val : buckets[c]) {
                result.push_back(val);
                if ((int)result.size() == k) break;
            }
        }
        return result;
    }
};
