// Difficulty: Medium | Time: O(log n) | Space: O(1) | Pattern: Binary Search | Use: Searching rotated logs and ring buffers
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = (int)nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            // If mid is bigger than the last element, the drop (minimum) is to the right
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        return nums[lo];
    }
};
