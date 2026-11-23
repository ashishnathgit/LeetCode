// Difficulty: Easy | Time: O(n) | Space: O(1) | Pattern: Two Pointers | Use: In-place buffer reversal without auxiliary allocations
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = (int)s.size() - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};
