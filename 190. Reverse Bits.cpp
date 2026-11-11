class Solution {
public:
    int reverseBits(int n) {
        // Work with unsigned so shifting never sign-extends
        uint32_t x = n, result = 0;

        // Move bits one at a time from the low end of x to the low end of result
        for (int i = 0; i < 32; ++i) {
            result = (result << 1) | (x & 1);
            x >>= 1;
        }
        return (int)result;
    }
};
