class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();

        // need[j] = minimum health needed when entering cell (i, j), filled bottom-up.
        // need[n] is a wall (INT_MAX); need[n - 1] starts at 1 as the cell below the princess.
        vector<int> need(n + 1, INT_MAX);
        need[n - 1] = 1;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Go toward the cheaper next cell; health must stay at least 1
                int nextNeed = min(need[j], need[j + 1]);
                need[j] = max(1, nextNeed - dungeon[i][j]);
            }
        }
        return need[0];
    }
};
