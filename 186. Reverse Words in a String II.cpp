// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Two Pointers | Use: In-place text edits on memory-limited systems
class Solution {
public:
    void reverseWords(vector<char>& s) {
        // Step 1: Reverse the whole array - words are now in the right order but spelled backward
        reverse(s.begin(), s.end());

        // Step 2: Reverse each word back
        int n = s.size(), start = 0;
        for (int end = 0; end <= n; ++end) {
            if (end == n || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
    }
};
