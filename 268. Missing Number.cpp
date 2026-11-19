// Difficulty: Easy | Time: O(n) | Space: O(1) | Pattern: Bit Manipulation | Use: Spotting a missing sequence number in packets or IDs
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // XOR every index and value; the only unpaired number is the missing one
        int result = nums.size();
        for (int i = 0; i < (int)nums.size(); ++i)
            result ^= i ^ nums[i];
        return result;
    }
};
