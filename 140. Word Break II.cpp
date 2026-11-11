// Difficulty: Hard | Time: O(2ⁿ) worst | Space: O(2ⁿ) worst | Pattern: Backtracking | Use: Generating every segmentation for spelling suggestions
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return build(s, 0, words, memo);
    }

private:
    // Returns every sentence that can be made from s[start..]
    vector<string> build(const string& s, int start, const unordered_set<string>& words,
                         unordered_map<int, vector<string>>& memo) {
        if (start == (int)s.size()) return {""};
        if (auto it = memo.find(start); it != memo.end()) return it->second;

        vector<string> sentences;
        for (int end = start + 1; end <= (int)s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (!words.count(word)) continue;

            for (const string& rest : build(s, end, words, memo)) {
                sentences.push_back(rest.empty() ? word : word + " " + rest);
            }
        }

        memo[start] = sentences;
        return sentences;
    }
};
