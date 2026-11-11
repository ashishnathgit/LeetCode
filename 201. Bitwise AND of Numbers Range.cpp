// Difficulty: Medium | Time: O(log n) | Space: O(1) | Pattern: Bit Manipulation | Use: Subnet and CIDR prefix calculation
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // The answer is the common binary prefix of left and right.
        // Clear right's lowest set bit until it is no longer above left.
        while (left < right) {
            right &= right - 1;
        }
        return right;
    }
};
