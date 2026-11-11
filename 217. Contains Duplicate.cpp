// Difficulty: Easy | Time: O(n) | Space: O(n) | Pattern: Hash Map | Use: Duplicate detection in uploads and sign-ups
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            // If we've already seen this number, it's a duplicate
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false; // All numbers were distinct
    }
};
