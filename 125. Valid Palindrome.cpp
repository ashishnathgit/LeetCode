// Difficulty: Easy | Time: O(n) | Space: O(1) | Pattern: Two Pointers | Use: Input normalization and validation
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = (int)s.size() - 1;

        while (left < right) {
            // Skip anything that is not a letter or digit
            if (!isalnum((unsigned char)s[left])) { left++; continue; }
            if (!isalnum((unsigned char)s[right])) { right--; continue; }

            if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
