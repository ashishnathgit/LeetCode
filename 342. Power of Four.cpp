// Difficulty: Easy | Time: O(1) | Space: O(1) | Pattern: Bit Manipulation | Use: Fast alignment and power-of-four bitmask checks in memory allocators
class Solution {
public:
    bool isPowerOfFour(int n) {
        // Exactly one set bit, located at an even bit position (0, 2, 4, ...)
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
    }
};
