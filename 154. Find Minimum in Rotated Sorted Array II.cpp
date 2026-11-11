// Difficulty: Hard | Time: O(log n) avg, O(n) worst | Space: O(1) | Pattern: Binary Search | Use: Searching rotated data that contains duplicates
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = (int)nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[hi]) {
                lo = mid + 1;   // Minimum is to the right
            } else if (nums[mid] < nums[hi]) {
                hi = mid;       // Minimum is at mid or to the left
            } else {
                hi--;           // Duplicate: can't tell which side, so shrink safely
            }
        }
        return nums[lo];
    }
};
