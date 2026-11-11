// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Two Pointers | Use: Stepping through configurations in order for exhaustive testing
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the rightmost index i where nums[i] < nums[i + 1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If found, swap nums[i] with the rightmost element larger than it
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix so it becomes the smallest order
        // (if no i was found, this reverses the whole array to the lowest permutation)
        reverse(nums.begin() + i + 1, nums.end());
    }
};
