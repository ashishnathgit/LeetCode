class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the graph: prereq -> course, and count each course's prerequisites
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (const auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }

        // Kahn's algorithm: the order courses become free is a valid schedule
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            for (int next : graph[course]) {
                if (--inDegree[next] == 0) q.push(next);
            }
        }

        // A cycle leaves some courses out: no valid order
        if ((int)order.size() != numCourses) return {};
        return order;
    }
};
