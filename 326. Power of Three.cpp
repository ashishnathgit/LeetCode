// Difficulty: Easy | Time: O(1) | Space: O(1) | Pattern: Math | Use: Divisibility test against the maximum 32-bit power of a prime
class Solution {
public:
    bool isPowerOfThree(int n) {
        // 3^19 = 1162261467 is the largest power of 3 fitting in signed 32-bit int
        return n > 0 && 1162261467 % n == 0;
    }
};
