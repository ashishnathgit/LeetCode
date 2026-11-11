class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // x ^ x = 0, so every pair cancels out and only the single number remains
        int result = 0;
        for (int num : nums) result ^= num;
        return result;
    }
};
