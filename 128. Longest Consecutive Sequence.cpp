class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Only start counting from the first number of a run
            if (numSet.count(num - 1)) continue;

            int length = 1;
            while (numSet.count(num + length)) length++;
            longest = max(longest, length);
        }
        return longest;
    }
};
