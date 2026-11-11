class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the graph: prereq -> course, and count each course's prerequisites
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (const auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }

        // Kahn's algorithm: repeatedly take courses with no remaining prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        int taken = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            taken++;
            for (int next : graph[course]) {
                if (--inDegree[next] == 0) q.push(next);
            }
        }

        // Any course never taken is stuck in a cycle
        return taken == numCourses;
    }
};
