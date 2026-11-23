// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Stack | Use: Greedy lexicographical deduplication of symbol streams
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int lastIdx[26] = {};
        for (int i = 0; i < (int)s.size(); ++i) {
            lastIdx[s[i] - 'a'] = i;
        }

        bool inStack[26] = {};
        string result;
        for (int i = 0; i < (int)s.size(); ++i) {
            int c = s[i] - 'a';
            if (inStack[c]) continue;

            // Pop larger characters that still appear later to keep result minimal
            while (!result.empty() && result.back() > s[i] && lastIdx[result.back() - 'a'] > i) {
                inStack[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(s[i]);
            inStack[c] = true;
        }
        return result;
    }
};
