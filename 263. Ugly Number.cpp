// Difficulty: Easy | Time: O(log n) | Space: O(1) | Pattern: Math | Use: Checking FFT-friendly sizes made only of small prime factors
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;

        // Strip out all allowed prime factors; only 1 should remain
        for (int p : {2, 3, 5})
            while (n % p == 0) n /= p;
        return n == 1;
    }
};
