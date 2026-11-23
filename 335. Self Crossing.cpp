// Difficulty: Hard | Time: O(n) | Space: O(1) | Pattern: Geometry | Use: Constant-memory collision detection for orthogonal polyline paths
class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        for (int i = 3; i < n; ++i) {
            if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) {
                return true;
            }
            if (i >= 4 && distance[i - 1] == distance[i - 3] &&
                (long long)distance[i] + distance[i - 4] >= distance[i - 2]) {
                return true;
            }
            if (i >= 5 && distance[i - 2] >= distance[i - 4] && distance[i - 1] <= distance[i - 3] &&
                (long long)distance[i] + distance[i - 4] >= distance[i - 2] &&
                (long long)distance[i - 1] + distance[i - 5] >= distance[i - 3]) {
                return true;
            }
        }
        return false;
    }
};
