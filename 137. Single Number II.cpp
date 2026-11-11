// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Bit Manipulation | Use: Bit-level state counters in checksums and hardware logic
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Each bit cycles through states 0 -> ones -> twos -> 0 as it is seen 1, 2, 3 times.
        // Bits seen three times reset, so 'ones' ends up holding the single number.
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};
