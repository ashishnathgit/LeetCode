// Difficulty: Medium | Time: O(n) | Space: O(n) | Pattern: String | Use: Text cleanup and tokenization
class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Split on whitespace (extra spaces are skipped automatically)
        istringstream in(s);
        vector<string> words;
        string word;
        while (in >> word) words.push_back(word);

        // Step 2: Join the words back in reverse order with single spaces
        string result;
        for (int i = (int)words.size() - 1; i >= 0; --i) {
            result += words[i];
            if (i > 0) result += ' ';
        }
        return result;
    }
};
