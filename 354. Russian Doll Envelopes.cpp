// Difficulty: Hard | Time: O(n log n) | Space: O(n) | Pattern: Binary Search | Use: 2D dominance chains via coordinate sorting and patience LIS
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort width ascending, height descending so equal widths cannot nest
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

        vector<int> tails;
        for (const auto& env : envelopes) {
            int h = env[1];
            auto it = lower_bound(tails.begin(), tails.end(), h);
            if (it == tails.end()) {
                tails.push_back(h);
            } else {
                *it = h;
            }
        }
        return (int)tails.size();
    }
};
