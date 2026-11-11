// Difficulty: Hard | Time: O(m·n·4ᴸ) | Space: O(total chars) | Pattern: Trie | Use: Word games and multi-pattern grid search
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Step 1: Put every word in a trie so one search checks all words at once
        TrieNode root;
        for (const string& w : words) {
            TrieNode* node = &root;
            for (char c : w) {
                auto& child = node->children[c - 'a'];
                if (!child) child = make_unique<TrieNode>();
                node = child.get();
            }
            node->word = w;
        }

        // Step 2: Start a search from every cell
        vector<string> result;
        for (int r = 0; r < (int)board.size(); ++r) {
            for (int c = 0; c < (int)board[0].size(); ++c) {
                dfs(board, r, c, &root, result);
            }
        }
        return result;
    }

private:
    struct TrieNode {
        unique_ptr<TrieNode> children[26];
        string word;  // Set on the node where a word ends
    };

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* parent, vector<string>& result) {
        char letter = board[r][c];
        if (letter == '#') return;  // Already on the current path

        TrieNode* node = parent->children[letter - 'a'].get();
        if (!node) return;

        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word.clear();  // Don't report the same word twice
        }

        board[r][c] = '#';
        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < (int)board.size() && nc >= 0 && nc < (int)board[0].size()) {
                dfs(board, nr, nc, node, result);
            }
        }
        board[r][c] = letter;

        // Prune: drop a node with no words left below it, so later searches skip it
        bool hasChildren = false;
        for (const auto& child : node->children) {
            if (child) { hasChildren = true; break; }
        }
        if (!hasChildren && node->word.empty()) {
            parent->children[letter - 'a'].reset();
        }
    }
};
