// Difficulty: Easy | Time: O(1) | Space: O(1) | Pattern: Bit Manipulation | Use: Validating buffer/allocation sizes
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A power of two has exactly one set bit.
        return n > 0 && (n & (n - 1)) == 0;
    }
};
