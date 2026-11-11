class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int best = 0;
        for (int i = 0; i < n; ++i) {
            // Count the other points by their slope from point i
            map<pair<int, int>, int> slopes;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Reduce the slope to lowest terms so equal slopes share a key
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize the sign so (1, 2) and (-1, -2) match
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                best = max(best, ++slopes[{dx, dy}] + 1);  // +1 for point i itself
            }
        }
        return best;
    }
};
