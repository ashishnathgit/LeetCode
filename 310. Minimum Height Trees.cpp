// Difficulty: Medium | Time: O(V + E) | Space: O(V + E) | Pattern: Topological Sort | Use: Finding graph centers in network topology and broadcast routing
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 2) {
            vector<int> res;
            for (int i = 0; i < n; ++i) res.push_back(i);
            return res;
        }

        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            ++deg[e[0]];
            ++deg[e[1]];
        }

        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) leaves.push(i);
        }

        // Peel leaf layers until 1 or 2 center nodes remain
        int remaining = n;
        while (remaining > 2) {
            int layerSize = leaves.size();
            remaining -= layerSize;
            for (int i = 0; i < layerSize; ++i) {
                int u = leaves.front();
                leaves.pop();
                for (int v : adj[u]) {
                    if (--deg[v] == 1) leaves.push(v);
                }
            }
        }

        vector<int> centers;
        while (!leaves.empty()) {
            centers.push_back(leaves.front());
            leaves.pop();
        }
        return centers;
    }
};
