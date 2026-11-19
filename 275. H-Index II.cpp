// Difficulty: Medium | Time: O(log n) | Space: O(1) | Pattern: Binary Search | Use: Threshold queries over pre-sorted metrics
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lo = 0, hi = n - 1;

        // Find the first index i where citations[i] >= n - i
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (citations[mid] >= n - mid) hi = mid - 1;
            else lo = mid + 1;
        }
        return n - lo;
    }
};
