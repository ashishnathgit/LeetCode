// Difficulty: Medium | Time: O(n·k) | Space: O(n + k) | Pattern: Dynamic Programming | Use: K-way merge generation of numbers with restricted prime factors
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> dp(n, 1);
        vector<int> idx(k, 0);

        for (int i = 1; i < n; ++i) {
            long long nextVal = LLONG_MAX;
            for (int j = 0; j < k; ++j) {
                nextVal = min(nextVal, (long long)dp[idx[j]] * primes[j]);
            }
            dp[i] = (int)nextVal;
            for (int j = 0; j < k; ++j) {
                if ((long long)dp[idx[j]] * primes[j] == nextVal) ++idx[j];
            }
        }
        return dp[n - 1];
    }
};
