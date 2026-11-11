// Difficulty: Medium | Time: O(total bricks) | Space: O(n) | Pattern: Hash Map | Use: Finding the best cut line (layout, shard boundaries)
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // Boosts C++ I/O speed for LeetCode's judge system
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int, int> gap_counts;
        int max_gaps = 0;
        
        for (const auto& row : wall) {
            int current_position = 0;
            
            // Loop through all bricks except the very last one in the row
            for (int i = 0; i < row.size() - 1; ++i) {
                current_position += row[i];
                gap_counts[current_position]++;
                max_gaps = max(max_gaps, gap_counts[current_position]);
            }
        }
        
        // Total rows minus the best possible gap alignment yields minimum cuts
        return wall.size() - max_gaps;
    }
};

