// Difficulty: Medium | Time: O(m * n) | Space: O(1) | Pattern: Matrix | Use: Cellular automata, in-place grid simulations
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        // Bit 0 = current state, bit 1 = next state (computed in place)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;
                for (int di = -1; di <= 1; ++di)
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (di == 0 && dj == 0) continue;
                        int r = i + di, c = j + dj;
                        if (r >= 0 && r < m && c >= 0 && c < n) live += board[r][c] & 1;
                    }

                if (live == 3 || (live == 2 && (board[i][j] & 1)))
                    board[i][j] |= 2;
            }
        }

        // Shift next state into place
        for (auto& row : board)
            for (int& cell : row) cell >>= 1;
    }
};
