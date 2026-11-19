// Difficulty: Easy | Time: O(n) | Space: O(1) | Pattern: Two Pointers | Use: Compacting arrays in-place, e.g. removing tombstoned entries
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // write points to where the next non-zero should go
        int write = 0;
        for (int read = 0; read < (int)nums.size(); ++read)
            if (nums[read] != 0) swap(nums[write++], nums[read]);
    }
};
