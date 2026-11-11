class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ranges;

        // Treat lower - 1 and upper + 1 as virtual neighbors on each side
        // (long long so the edges can't overflow)
        long long prev = (long long)lower - 1;

        for (size_t i = 0; i <= nums.size(); ++i) {
            long long current = i < nums.size() ? nums[i] : (long long)upper + 1;

            // A gap of 2 or more means numbers are missing in between
            if (current - prev >= 2) {
                ranges.push_back({(int)(prev + 1), (int)(current - 1)});
            }
            prev = current;
        }
        return ranges;
    }
};
