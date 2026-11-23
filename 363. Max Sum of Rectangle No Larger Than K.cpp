// Difficulty: Hard | Time: O(min(m,n)² · max(m,n) · log(max(m,n))) | Space: O(max(m,n)) | Pattern: Matrix | Use: Budget-bounded 2D region queries in heatmaps and image analysis
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        bool rowMajor = (m <= n);
        int outer = rowMajor ? m : n;
        int inner = rowMajor ? n : m;

        int best = INT_MIN;
        for (int i = 0; i < outer; ++i) {
            vector<int> lineSum(inner, 0);
            for (int j = i; j < outer; ++j) {
                for (int p = 0; p < inner; ++p) {
                    lineSum[p] += rowMajor ? matrix[j][p] : matrix[p][j];
                }

                // Fast path: if unconstrained max subarray is <= k, skip ordered set
                int cur = 0, kadane = INT_MIN;
                for (int v : lineSum) {
                    cur = max(v, cur + v);
                    kadane = max(kadane, cur);
                }
                if (kadane <= k) {
                    best = max(best, kadane);
                    if (best == k) return k;
                    continue;
                }

                set<int> prefixes{0};
                int sum = 0;
                for (int v : lineSum) {
                    sum += v;
                    auto it = prefixes.lower_bound(sum - k);
                    if (it != prefixes.end()) {
                        best = max(best, sum - *it);
                        if (best == k) return k;
                    }
                    prefixes.insert(sum);
                }
            }
        }
        return best;
    }
};
