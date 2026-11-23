// Difficulty: Hard | Time: O(n log n) | Space: O(n) | Pattern: Divide and Conquer | Use: Counting bounded subarray aggregates via merge sort
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<long long> scratch(n + 1);
        return mergeCount(prefix, scratch, 0, n + 1, lower, upper);
    }

private:
    int mergeCount(vector<long long>& prefix, vector<long long>& scratch,
                   int lo, int hi, int lower, int upper) {
        if (hi - lo <= 1) return 0;
        int mid = lo + (hi - lo) / 2;
        int count = mergeCount(prefix, scratch, lo, mid, lower, upper)
                  + mergeCount(prefix, scratch, mid, hi, lower, upper);

        int l = mid, r = mid;
        for (int i = lo; i < mid; ++i) {
            while (l < hi && prefix[l] - prefix[i] < lower) ++l;
            while (r < hi && prefix[r] - prefix[i] <= upper) ++r;
            count += r - l;
        }

        int i = lo, j = mid, k = lo;
        while (i < mid && j < hi) {
            scratch[k++] = (prefix[i] <= prefix[j]) ? prefix[i++] : prefix[j++];
        }
        while (i < mid) scratch[k++] = prefix[i++];
        while (j < hi) scratch[k++] = prefix[j++];
        for (int p = lo; p < hi; ++p) prefix[p] = scratch[p];

        return count;
    }
};
