class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        // Reverse all, then reverse the first k and the rest separately
        // e.g. [1,2,3,4,5], k=2 -> [5,4,3,2,1] -> [4,5,3,2,1] -> [4,5,1,2,3]
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
