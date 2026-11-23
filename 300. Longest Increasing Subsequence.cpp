// Difficulty: Medium | Time: O(n log n) | Space: O(n) | Pattern: Binary Search | Use: Version ordering, diff alignment, and patience sorting
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;  // tails[k] = smallest tail of an increasing subsequence of length k + 1
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }
        return (int)tails.size();
    }
};
