// Difficulty: Hard | Time: O(n·k) | Space: O(k) | Pattern: Dynamic Programming | Use: Trading strategies with a transaction limit
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // With enough transactions, take every upward move
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i) profit += max(0, prices[i] - prices[i - 1]);
            return profit;
        }

        // buy[t]  = best balance while holding a stock in the t-th transaction
        // sell[t] = best balance after finishing t transactions
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);

        for (int price : prices) {
            for (int t = 1; t <= k; ++t) {
                buy[t] = max(buy[t], sell[t - 1] - price);
                sell[t] = max(sell[t], buy[t] + price);
            }
        }
        return sell[k];
    }
};
