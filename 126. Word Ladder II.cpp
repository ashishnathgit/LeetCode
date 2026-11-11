// Difficulty: Hard | Time: O(N·L·26 + paths) | Space: O(N·L) | Pattern: Graph | Use: Listing every shortest route in navigation or network hops
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> unvisited(wordList.begin(), wordList.end());
        if (!unvisited.count(endWord)) return {};
        unvisited.erase(beginWord);

        // parents[w] = every word one step closer to beginWord on a shortest path
        unordered_map<string, vector<string>> parents;
        vector<string> level = {beginWord};
        bool found = false;

        // Step 1: BFS one layer at a time, recording parents
        while (!level.empty() && !found) {
            unordered_set<string> nextLevel;

            for (const string& word : level) {
                string next = word;
                for (size_t i = 0; i < next.size(); ++i) {
                    char original = next[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == original) continue;
                        next[i] = c;
                        if (unvisited.count(next)) {
                            parents[next].push_back(word);
                            nextLevel.insert(next);
                            if (next == endWord) found = true;
                        }
                    }
                    next[i] = original;
                }
            }

            // Remove words only after the whole layer is done,
            // so a word can collect parents from several words in the previous layer
            for (const string& w : nextLevel) unvisited.erase(w);
            level.assign(nextLevel.begin(), nextLevel.end());
        }

        if (!found) return {};

        // Step 2: Walk the parent links back from endWord to build every path
        vector<vector<string>> result;
        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, result);
        return result;
    }

private:
    void backtrack(const string& word, const string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            result.emplace_back(path.rbegin(), path.rend());
            return;
        }
        for (const string& parent : parents[word]) {
            path.push_back(parent);
            backtrack(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};
