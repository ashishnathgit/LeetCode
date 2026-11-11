// Difficulty: Medium | Time: O(m·n) | Space: O(m·n) | Pattern: Graph | Use: Flood fill and region capture in image editors and board games
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        queue<pair<int, int>> q;

        // Step 1: Every 'O' on the border can't be captured; mark it safe ('#')
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                bool onBorder = r == 0 || r == rows - 1 || c == 0 || c == cols - 1;
                if (onBorder && board[r][c] == 'O') {
                    board[r][c] = '#';
                    q.push({r, c});
                }
            }
        }

        // Step 2: Spread the safe mark to every 'O' connected to the border
        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (const auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'O') {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }

        // Step 3: Unmarked 'O's are surrounded -> 'X'; safe cells go back to 'O'
        for (auto& row : board) {
            for (char& cell : row) {
                cell = (cell == '#') ? 'O' : 'X';
            }
        }
    }
};
