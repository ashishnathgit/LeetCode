// Difficulty: Easy | Time: O(n) | Space: O(n) | Pattern: Hash Map | Use: Matching transaction pairs that reconcile to a target amount
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // value -> index of numbers seen so far
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (seen.count(need)) {
                return {seen[need], i};
            }
            seen[nums[i]] = i;
        }

        return {}; // problem guarantees exactly one answer
    }
};
