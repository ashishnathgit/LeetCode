// Difficulty: Medium | Time: O(L) add, O(26ᵈ·L) search | Space: O(total chars) | Pattern: Trie | Use: Wildcard dictionary search
class WordDictionary {
public:
    WordDictionary() : root(make_unique<Node>()) {}

    void addWord(string word) {
        Node* node = root.get();
        for (char c : word) {
            auto& child = node->children[c - 'a'];
            if (!child) child = make_unique<Node>();
            node = child.get();
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return match(word, 0, root.get());
    }

private:
    struct Node {
        unique_ptr<Node> children[26];
        bool isEnd = false;
    };

    unique_ptr<Node> root;

    bool match(const string& word, int i, Node* node) {
        if (i == (int)word.size()) return node->isEnd;

        // '.' matches any letter, so try every child
        if (word[i] == '.') {
            for (auto& child : node->children) {
                if (child && match(word, i + 1, child.get())) return true;
            }
            return false;
        }

        Node* child = node->children[word[i] - 'a'].get();
        return child && match(word, i + 1, child);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
