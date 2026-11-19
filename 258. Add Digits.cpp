// Difficulty: Easy | Time: O(1) | Space: O(1) | Pattern: Math | Use: Digital-root checksums (e.g. quick validation of IDs)
class Solution {
public:
    int addDigits(int num) {
        // Digital root formula: result cycles 1..9 based on num mod 9
        if (num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};
