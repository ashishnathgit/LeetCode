// Difficulty: Hard | Time: O(N·L·26) | Space: O(N·L) | Pattern: Graph | Use: Shortest transformation chains (gene mutation, spelling fixes)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> unvisited(wordList.begin(), wordList.end());
        if (!unvisited.count(endWord)) return 0;
        unvisited.erase(beginWord);

        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        // BFS: the first time we reach endWord is the shortest path
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                string word = q.front();
                q.pop();
                if (word == endWord) return steps;

                // Try every one-letter change
                for (size_t i = 0; i < word.size(); ++i) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (unvisited.erase(word)) q.push(word);
                    }
                    word[i] = original;
                }
            }
            steps++;
        }
        return 0;
    }
};
