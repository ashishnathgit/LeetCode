class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int windowSize = x;
        // There are n - windowSize + 1 possible segments of length x.
        vector<long long> segCost(n - windowSize + 1, 0);
        
        // Two multisets to support a sliding window median calculation.
        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;
        
        // Helper lambda to rebalance the two multisets.
        auto rebalance = [&]() {
            // We maintain left.size() == right.size() or left.size() == right.size()+1.
            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                int val = *it;
                left.erase(it);
                sumLeft -= val;
                right.insert(val);
                sumRight += val;
            }
            while (left.size() < right.size()) {
                auto it = right.begin();
                int val = *it;
                right.erase(it);
                sumRight -= val;
                left.insert(val);
                sumLeft += val;
            }
        };
        
        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            } else {
                right.insert(val);
                sumRight += val;
            }
            rebalance();
        };
        
        auto removeVal = [&](int val) {
            if (!left.empty() && val <= *left.rbegin()){
                auto it = left.find(val);
                if (it != left.end()){
                    left.erase(it);
                    sumLeft -= val;
                }
            } else {
                auto it = right.find(val);
                if (it != right.end()){
                    right.erase(it);
                    sumRight -= val;
                }
            }
            rebalance();
        };
        
        // Process the sliding window over nums.
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= windowSize - 1) {
                // When the window size is exactly x, compute the cost.
                // The median is the largest element in 'left'
                int median = *left.rbegin();
                // Cost is the sum of differences to the median.
                long long costLeft = (long long)median * left.size() - sumLeft;
                long long costRight = sumRight - (long long)median * right.size();
                segCost[i - windowSize + 1] = costLeft + costRight;
                
                // Remove the element that's going out of the window.
                removeVal(nums[i - windowSize + 1]);
            }
        }
        
        // DP: dp[i][j] is the minimum cost to form j segments using the first i elements.
        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; i++) {
            // Option 1: skip the (i-1)-th element.
            for (int j = 0; j <= k; j++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
            // Option 2: if a segment ending at i-1 can be taken.
            if (i >= windowSize) {
                for (int j = 1; j <= k; j++) {
                    if (dp[i - windowSize][j - 1] != INF) {
                        dp[i][j] = min(dp[i][j], dp[i - windowSize][j - 1] + segCost[i - windowSize]);
                    }
                }
            }
        }
        
        return dp[n][k] >= INF ? -1 : dp[n][k];
    }
};
