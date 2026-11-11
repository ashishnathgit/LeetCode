// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Hash Map | Use: Pairing complementary items, like matching buy and sell orders
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // Boosts C++ I/O speed for LeetCode's judge system
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        // Fixed-size frequency matrix (26x26) initialized to 0
        int count[26][26] = {0};
        int length = 0;
        
        for (const string& word : words) {
            int i = word[0] - 'a';
            int j = word[1] - 'a';
            
            // If the reversed word has a pending match, pair them up
            if (count[j][i] > 0) {
                length += 4;
                count[j][i]--; // Consume the matching pair
            } else {
                count[i][j]++; // Store the word for a future match
            }
        }
        
        // Check if there is any remaining identical-letter word to put in the dead center
        for (int i = 0; i < 26; ++i) {
            if (count[i][i] > 0) {
                length += 2;
                break; // Only a single word can occupy the absolute center
            }
        }
        
        return length;
    }
};

