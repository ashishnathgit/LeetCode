class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Step 1: Left to right - beat the left neighbor if rated higher
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        }

        // Step 2: Right to left - beat the right neighbor too, keeping the larger count
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};
