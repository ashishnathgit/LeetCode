class Solution {
public:
    int longestPalindrome(string s, string t) {
        int ans = 0;
        int n = s.size(), m = t.size();
        
        // Helper lambda to check if a string is a palindrome.
        auto isPalindrome = [&](const string &str) -> bool {
            int i = 0, j = str.size() - 1;
            while (i < j) {
                if (str[i] != str[j])
                    return false;
                i++; j--;
            }
            return true;
        };
        
        // Enumerate all substrings of s (including empty substring).
        // i and j are the start and end indices (with j being one past the end)
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                string subS = s.substr(i, j - i);
                // Enumerate all substrings of t (including empty substring).
                for (int k = 0; k <= m; k++) {
                    for (int l = k; l <= m; l++) {
                        string subT = t.substr(k, l - k);
                        string candidate = subS + subT;
                        // Check that candidate is non-empty and a palindrome.
                        if (!candidate.empty() && isPalindrome(candidate)) {
                            ans = max(ans, (int)candidate.size());
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};