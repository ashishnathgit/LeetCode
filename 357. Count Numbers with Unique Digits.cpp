// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Math | Use: Counting distinct-digit identifiers and permutation spaces
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int total = 10;
        int unique = 9;
        int available = 9;
        for (int digits = 2; digits <= n && available > 0; ++digits) {
            unique *= available--;
            total += unique;
        }
        return total;
    }
};
