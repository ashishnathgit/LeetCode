// Difficulty: Easy | Time: O(n) | Space: O(1) | Pattern: Two Pointers | Use: Compressing ID lists (e.g. "pages 1-5, 8")
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        for (int i = 0; i < n;) {
            int j = i;
            while (j + 1 < n && (long long)nums[j + 1] == (long long)nums[j] + 1) j++;
            if (i == j) res.push_back(to_string(nums[i]));
            else res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            i = j + 1;
        }
        return res;
    }
};
