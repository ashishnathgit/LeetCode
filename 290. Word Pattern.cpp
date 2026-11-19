// Difficulty: Easy | Time: O(n) | Space: O(n) | Pattern: Hash Map | Use: Validating one-to-one mappings, e.g. schema field aliases
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream stream(s);
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        string word;
        int i = 0;
        while (stream >> word) {
            if (i == (int)pattern.size()) return false;
            char c = pattern[i++];

            // The mapping must be a bijection in both directions
            auto cw = charToWord.find(c);
            auto wc = wordToChar.find(word);
            if (cw != charToWord.end() && cw->second != word) return false;
            if (wc != wordToChar.end() && wc->second != c) return false;
            charToWord[c] = word;
            wordToChar[word] = c;
        }
        return i == (int)pattern.size();
    }
};
