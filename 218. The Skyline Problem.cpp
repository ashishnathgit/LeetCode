// Difficulty: Hard | Time: O(n log n) | Space: O(n) | Pattern: Sweep Line + Multiset | Use: Rendering silhouettes and interval union heights
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Start events use negative height so starts sort before ends at the same x,
        // and taller starts come first.
        vector<pair<int, int>> events;
        for (auto& b : buildings) {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }
        sort(events.begin(), events.end());

        multiset<int> heights = {0};
        vector<vector<int>> res;
        int prev = 0;
        for (auto& [x, h] : events) {
            if (h < 0) heights.insert(-h);
            else heights.erase(heights.find(h));
            int cur = *heights.rbegin();
            if (cur != prev) {
                res.push_back({x, cur});
                prev = cur;
            }
        }
        return res;
    }
};
