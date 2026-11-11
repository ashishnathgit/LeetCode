// Difficulty: Easy | Time: O(1) | Space: O(1) | Pattern: Bit Manipulation | Use: Counting set flags in permissions and bitmap indexes
class Solution {
public:
    int hammingWeight(int n) {
        // n & (n - 1) clears the lowest set bit, so loop once per 1 bit
        int count = 0;
        while (n) {
            n &= n - 1;
            count++;
        }
        return count;
    }
};
