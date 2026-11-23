// Difficulty: Hard | Time: O(n · k²) | Space: O(n · k) | Pattern: Hash Map | Use: Indexing prefix/suffix symmetries in dictionary string matching
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> index;
        index.reserve(words.size());
        for (int i = 0; i < (int)words.size(); ++i) {
            index[words[i]] = i;
        }

        vector<vector<int>> pairs;
        for (int i = 0; i < (int)words.size(); ++i) {
            const string& w = words[i];
            int len = w.size();
            for (int cut = 0; cut <= len; ++cut) {
                if (isPal(w, 0, cut - 1)) {
                    string revRight = w.substr(cut);
                    reverse(revRight.begin(), revRight.end());
                    auto it = index.find(revRight);
                    if (it != index.end() && it->second != i) {
                        pairs.push_back({it->second, i});
                    }
                }
                // Require non-empty right half here so empty-half pairs aren't emitted twice
                if (cut < len && isPal(w, cut, len - 1)) {
                    string revLeft = w.substr(0, cut);
                    reverse(revLeft.begin(), revLeft.end());
                    auto it = index.find(revLeft);
                    if (it != index.end() && it->second != i) {
                        pairs.push_back({i, it->second});
                    }
                }
            }
        }
        return pairs;
    }

private:
    bool isPal(const string& s, int l, int r) const {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
