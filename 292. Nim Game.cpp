// Difficulty: Easy | Time: O(1) | Space: O(1) | Pattern: Math | Use: Game theory reasoning for turn-based strategy engines
class Solution {
public:
    bool canWinNim(int n) {
        // Any multiple of 4 is a losing position for the player to move
        return n % 4 != 0;
    }
};
