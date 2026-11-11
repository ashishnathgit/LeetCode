class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();

        // Keep s as the shorter string
        if (m > n) return isOneEditDistance(t, s);
        if (n - m > 1) return false;

        for (int i = 0; i < m; ++i) {
            if (s[i] != t[i]) {
                // Same length: replace one character. Otherwise: insert one into s.
                if (m == n) return s.compare(i + 1, string::npos, t, i + 1, string::npos) == 0;
                return s.compare(i, string::npos, t, i + 1, string::npos) == 0;
            }
        }

        // All of s matched, so t must have exactly one extra character at the end
        return n - m == 1;
    }
};
