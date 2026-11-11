// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Dynamic Programming | Use: Picking non-conflicting jobs or ads for maximum value
class Solution {
public:
    int rob(vector<int>& nums) {
        // prev1 = best up to the previous house, prev2 = best up to the one before it
        int prev2 = 0, prev1 = 0;

        for (int money : nums) {
            // Either skip this house, or rob it and add the best from two houses back
            int current = max(prev1, prev2 + money);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
