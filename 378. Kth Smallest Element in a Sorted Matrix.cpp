// Difficulty: Medium | Time: O(n · log(max - min)) | Space: O(1) | Pattern: Binary Search | Use: Order-statistic selection over sorted 2D tables without merging
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countLessOrEqual(matrix, mid) < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }

private:
    int countLessOrEqual(const vector<vector<int>>& matrix, int target) const {
        int n = matrix.size();
        int r = n - 1, c = 0, count = 0;
        while (r >= 0 && c < n) {
            if (matrix[r][c] <= target) {
                count += r + 1;
                ++c;
            } else {
                --r;
            }
        }
        return count;
    }
};
