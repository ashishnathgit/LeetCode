class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array to minimize the binary search range
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        
        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            // Boundary edge cases: handle out-of-bounds using INT_MIN and INT_MAX
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            // Check if the current split partition is valid
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total element count is odd, max of left partition is the median
                if ((m + n) % 2 != 0) {
                    return max(maxLeft1, maxLeft2);
                } 
                // If total element count is even, average the borders
                else {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
            } 
            // We are too far right in nums1, must move left
            else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            } 
            // We are too far left in nums1, must move right
            else {
                low = partition1 + 1;
            }
        }
        
        return 0.0;
    }
};

