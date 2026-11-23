// Difficulty: Hard | Time: O(E log E) | Space: O(E) | Pattern: Graph | Use: Lexicographically smallest Eulerian path reconstruction for routing
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for (const auto& t : tickets) {
            adj[t[0]].push(t[1]);
        }

        vector<string> route;
        vector<string> st{"JFK"};
        while (!st.empty()) {
            string& curr = st.back();
            auto it = adj.find(curr);
            if (it != adj.end() && !it->second.empty()) {
                string next = it->second.top();
                it->second.pop();
                st.push_back(std::move(next));
            } else {
                route.push_back(std::move(curr));
                st.pop_back();
            }
        }
        reverse(route.begin(), route.end());
        return route;
    }
};
