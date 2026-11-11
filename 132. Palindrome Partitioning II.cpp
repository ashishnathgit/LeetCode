class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // cuts[i] = min cuts for the prefix s[0..i-1]
        // cuts[0] = -1 so a prefix that is itself a palindrome needs 0 cuts
        vector<int> cuts(n + 1);
        for (int i = 0; i <= n; ++i) cuts[i] = i - 1;

        // Expand around every center; each palindrome s[l..r] gives cuts[r+1] a candidate
        for (int center = 0; center < n; ++center) {
            // Odd length
            for (int l = center, r = center; l >= 0 && r < n && s[l] == s[r]; --l, ++r) {
                cuts[r + 1] = min(cuts[r + 1], cuts[l] + 1);
            }
            // Even length
            for (int l = center, r = center + 1; l >= 0 && r < n && s[l] == s[r]; --l, ++r) {
                cuts[r + 1] = min(cuts[r + 1], cuts[l] + 1);
            }
        }
        return cuts[n];
    }
};
