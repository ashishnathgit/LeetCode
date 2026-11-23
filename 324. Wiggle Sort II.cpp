// Difficulty: Medium | Time: O(n log n) | Space: O(n) | Pattern: Sorting | Use: Interleaving sorted partitions to separate equal median values
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int n = nums.size();
        int lo = (n - 1) / 2;
        int hi = n - 1;
        // Fill from the largest elements of each half downward to keep duplicate medians apart
        for (int i = 0; i < n; ++i) {
            nums[i] = (i % 2 == 0) ? sorted[lo--] : sorted[hi--];
        }
    }
};
