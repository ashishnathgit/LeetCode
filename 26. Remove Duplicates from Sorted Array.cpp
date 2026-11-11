// Difficulty: Easy | Time: O(n) | Space: O(1) | Pattern: Two Pointers | Use: Deduplicating sorted log or event streams
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto newEnd = unique(nums.begin() , nums.end());

        nums.erase(newEnd,nums.end());

        return nums.size();
        
    }
};
