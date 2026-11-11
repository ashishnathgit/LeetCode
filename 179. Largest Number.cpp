// Difficulty: Medium | Time: O(n log n) | Space: O(n) | Pattern: Sorting | Use: Ordering items with a custom comparator
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        strs.reserve(nums.size());
        for (int num : nums) strs.push_back(to_string(num));

        // a goes before b if putting it first makes a bigger number
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        // All zeros: avoid returning "000"
        if (strs[0] == "0") return "0";

        string result;
        for (const string& s : strs) result += s;
        return result;
    }
};
