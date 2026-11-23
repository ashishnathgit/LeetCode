// Difficulty: Easy | Time: O(log n) | Space: O(1) | Pattern: Binary Search | Use: Integer root checking without floating-point rounding error
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long lo = 1, hi = num;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long sq = mid * mid;
            if (sq == num) return true;
            if (sq < num) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};
