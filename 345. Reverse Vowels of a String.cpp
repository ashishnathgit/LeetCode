// Difficulty: Easy | Time: O(n) | Space: O(1) | Pattern: Two Pointers | Use: Selective in-place character swapping over filtered positions
class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char c) {
            c = tolower(static_cast<unsigned char>(c));
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int l = 0, r = (int)s.size() - 1;
        while (l < r) {
            while (l < r && !isVowel(s[l])) ++l;
            while (l < r && !isVowel(s[r])) --r;
            if (l < r) swap(s[l++], s[r--]);
        }
        return s;
    }
};
