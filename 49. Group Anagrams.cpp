class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Key: the word with its letters sorted; anagrams share the same key
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        // Collect each group into the result
        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& [key, words] : groups) {
            result.push_back(std::move(words));
        }

        return result;
    }
};
