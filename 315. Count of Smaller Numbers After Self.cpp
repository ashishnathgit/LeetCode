// Difficulty: Hard | Time: O(n log n) | Space: O(n) | Pattern: Divide and Conquer | Use: Computing right-hand inversion counts in ranking analytics
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        int m = sorted.size();
        vector<int> tree(m + 1, 0);
        auto add = [&](int idx) {
            for (; idx <= m; idx += idx & -idx) ++tree[idx];
        };
        auto query = [&](int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx) sum += tree[idx];
            return sum;
        };

        int n = nums.size();
        vector<int> counts(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            int rank = (int)(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin()) + 1;
            counts[i] = query(rank - 1);
            add(rank);
        }
        return counts;
    }
};
