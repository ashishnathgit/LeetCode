class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = (int)nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            // Going uphill to the right means a peak exists on the right
            if (nums[mid] < nums[mid + 1]) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
