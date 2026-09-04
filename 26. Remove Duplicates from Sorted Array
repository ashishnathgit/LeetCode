class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto newEnd = unique(nums.begin() , nums.end());

        nums.erase(newEnd,nums.end());

        return nums.size();
        
    }
};
