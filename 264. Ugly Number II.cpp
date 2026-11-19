// Difficulty: Medium | Time: O(n) | Space: O(n) | Pattern: Dynamic Programming | Use: Merging multiple sorted generated streams in order
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;

        // Three pointers: each tracks the next number to multiply by 2, 3, 5
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; ++i) {
            int next2 = ugly[i2] * 2, next3 = ugly[i3] * 3, next5 = ugly[i5] * 5;
            ugly[i] = min({next2, next3, next5});

            // Advance every pointer that produced the minimum (avoids duplicates)
            if (ugly[i] == next2) ++i2;
            if (ugly[i] == next3) ++i3;
            if (ugly[i] == next5) ++i5;
        }
        return ugly[n - 1];
    }
};
