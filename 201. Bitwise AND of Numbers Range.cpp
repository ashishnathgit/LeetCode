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
