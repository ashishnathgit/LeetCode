// Difficulty: Easy | Time: O(n) | Space: O(k) | Pattern: Sliding Window + Hash Set | Use: Detecting repeated events within a time window
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (i > k) window.erase(nums[i - k - 1]);
            if (!window.insert(nums[i]).second) return true;
        }
        return false;
    }
};
