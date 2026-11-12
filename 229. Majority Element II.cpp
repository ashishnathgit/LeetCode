// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Boyer-Moore Voting | Use: Finding heavy hitters in data streams
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // At most two values can appear more than n/3 times.
        int c1 = 0, c2 = 1, n1 = 0, n2 = 0;
        for (int x : nums) {
            if (x == c1) n1++;
            else if (x == c2) n2++;
            else if (n1 == 0) { c1 = x; n1 = 1; }
            else if (n2 == 0) { c2 = x; n2 = 1; }
            else { n1--; n2--; }
        }
        n1 = n2 = 0;
        for (int x : nums) {
            if (x == c1) n1++;
            else if (x == c2) n2++;
        }
        vector<int> res;
        int n = nums.size();
        if (n1 > n / 3) res.push_back(c1);
        if (n2 > n / 3) res.push_back(c2);
        return res;
    }
};
