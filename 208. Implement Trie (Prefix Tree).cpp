class Trie {
public:
    Trie() : root(make_unique<Node>()) {}

    void insert(string word) {
        Node* node = root.get();
        for (char c : word) {
            auto& child = node->children[c - 'a'];
            if (!child) child = make_unique<Node>();
            node = child.get();
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = find(word);
        return node && node->isEnd;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    struct Node {
        unique_ptr<Node> children[26];
        bool isEnd = false;
    };

    unique_ptr<Node> root;

    // Follows the path for s; returns nullptr if it breaks off
    Node* find(const string& s) {
        Node* node = root.get();
        for (char c : s) {
            node = node->children[c - 'a'].get();
            if (!node) return nullptr;
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
