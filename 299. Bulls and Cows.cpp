// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Hash Map | Use: Exact vs. positional mismatch scoring in code-breaking and fuzzy matching
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int balance[10] = {};  // Positive = excess in secret, negative = excess in guess

        for (int i = 0; i < (int)secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                int s = secret[i] - '0';
                int g = guess[i] - '0';
                if (balance[s] < 0) ++cows;
                if (balance[g] > 0) ++cows;
                ++balance[s];
                --balance[g];
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
