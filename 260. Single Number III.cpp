// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Bit Manipulation | Use: Finding two mismatched records between datasets
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // XOR of everything equals a ^ b (pairs cancel out)
        unsigned int xorAll = 0;
        for (int n : nums) xorAll ^= n;

        // Lowest set bit is a bit where a and b differ; split by it
        unsigned int diffBit = xorAll & (~xorAll + 1);
        int a = 0, b = 0;
        for (int n : nums) {
            if (n & diffBit) a ^= n;
            else b ^= n;
        }
        return {a, b};
    }
};
