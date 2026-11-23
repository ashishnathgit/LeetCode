// Difficulty: Medium | Time: O(1) | Space: O(1) | Pattern: Bit Manipulation | Use: Half-adder carry propagation in low-level arithmetic logic
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = static_cast<unsigned int>(a & b) << 1;
            a ^= b;
            b = static_cast<int>(carry);
        }
        return a;
    }
};
