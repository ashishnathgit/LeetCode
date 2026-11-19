// Difficulty: Easy | Time: O(n) | Space: O(1) | Pattern: Hash Map | Use: Detecting reordered content, e.g. dedup of shuffled tokens
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        // Count letters up in s and down in t; all must cancel out
        int counts[26] = {0};
        for (int i = 0; i < (int)s.size(); ++i) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int c : counts)
            if (c != 0) return false;
        return true;
    }
};
