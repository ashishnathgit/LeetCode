// Difficulty: Medium | Time: O(log n) | Space: O(1) | Pattern: Math | Use: Number theory in big-number libraries
class Solution {
public:
    int trailingZeroes(int n) {
        // Each trailing zero needs a 5 (2s are always more plentiful).
        // Count multiples of 5, 25, 125, ... since each adds one more factor of 5.
        int count = 0;
        while (n > 0) {
            n /= 5;
            count += n;
        }
        return count;
    }
};
