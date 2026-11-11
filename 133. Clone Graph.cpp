/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Maps each original node to its copy (also works as the visited set)
        unordered_map<Node*, Node*> copies;
        copies[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (Node* neighbor : current->neighbors) {
                if (!copies.count(neighbor)) {
                    copies[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                copies[current]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copies[node];
    }
};
