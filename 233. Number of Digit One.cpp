// Difficulty: Hard | Time: O(log n) | Space: O(1) | Pattern: Math / Digit Counting | Use: Digit frequency analysis (e.g. Benford checks)
class Solution {
public:
    int countDigitOne(int n) {
        // For each place value, count how many times that digit is 1 across 1..n.
        long long count = 0;
        for (long long p = 1; p <= n; p *= 10) {
            long long high = n / (p * 10), cur = (n / p) % 10, low = n % p;
            if (cur == 0) count += high * p;
            else if (cur == 1) count += high * p + low + 1;
            else count += (high + 1) * p;
        }
        return count;
    }
};
