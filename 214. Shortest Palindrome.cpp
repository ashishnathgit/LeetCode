// Difficulty: Hard | Time: O(n) | Space: O(n) | Pattern: String | Use: KMP pattern matching in editors and DNA search
class Solution {
public:
    string shortestPalindrome(string s) {
        // Find the longest prefix of s that is a palindrome; then mirror the rest in front.
        // That prefix is the longest prefix of s that is also a suffix of reverse(s),
        // which the KMP prefix table of s + "#" + reverse(s) gives us in O(n).
        string rev(s.rbegin(), s.rend());
        string combined = s + "#" + rev;

        vector<int> lps(combined.size(), 0);
        for (int i = 1; i < (int)combined.size(); ++i) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) len = lps[len - 1];
            if (combined[i] == combined[len]) len++;
            lps[i] = len;
        }

        int palindromeLen = lps.back();
        return rev.substr(0, s.size() - palindromeLen) + s;
    }
};
