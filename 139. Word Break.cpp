class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int maxLen = 0;
        for (const string& w : wordDict) maxLen = max(maxLen, (int)w.size());

        int n = s.size();
        // canBreak[i] = whether the prefix s[0..i-1] can be split into words
        vector<bool> canBreak(n + 1, false);
        canBreak[0] = true;

        for (int end = 1; end <= n; ++end) {
            // Only check pieces no longer than the longest word
            for (int start = end - 1; start >= 0 && end - start <= maxLen; --start) {
                if (canBreak[start] && words.count(s.substr(start, end - start))) {
                    canBreak[end] = true;
                    break;
                }
            }
        }
        return canBreak[n];
    }
};
