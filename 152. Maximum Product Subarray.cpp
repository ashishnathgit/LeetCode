class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Track both the largest and smallest product ending here:
        // a negative number turns the smallest into the largest.
        // double avoids overflow in intermediate products.
        double best = nums[0], curMax = nums[0], curMin = nums[0];

        for (int i = 1; i < (int)nums.size(); ++i) {
            double x = nums[i];
            if (x < 0) swap(curMax, curMin);

            curMax = max(x, curMax * x);
            curMin = min(x, curMin * x);
            best = max(best, curMax);
        }
        return (int)best;
    }
};
