// Difficulty: Easy | Time: O(n) | Space: O(n) | Pattern: Bit Manipulation | Use: Precomputing popcount lookup tables for bitset analytics
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
    }
};
