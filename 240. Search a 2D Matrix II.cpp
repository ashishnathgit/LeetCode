// Difficulty: Medium | Time: O(m + n) | Space: O(1) | Pattern: Staircase Search | Use: Lookups in row/column-sorted tables
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Start top-right: moving left decreases, moving down increases.
        int r = 0, c = matrix[0].size() - 1;
        while (r < (int)matrix.size() && c >= 0) {
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] > target) c--;
            else r++;
        }
        return false;
    }
};
