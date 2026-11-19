// Difficulty: Easy | Time: O(log n) | Space: O(1) | Pattern: Binary Search | Use: git bisect — finding the commit that introduced a bug
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;

        // Narrow down to the first version that reports bad
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2; // avoids overflow
            if (isBadVersion(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
