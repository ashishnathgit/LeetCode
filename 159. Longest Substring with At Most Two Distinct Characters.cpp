class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int counts[128] = {0};
        int distinct = 0, left = 0, best = 0;

        // Sliding window that always holds at most two distinct characters
        for (int right = 0; right < (int)s.size(); ++right) {
            if (counts[(unsigned char)s[right]]++ == 0) distinct++;

            // Shrink from the left until only two distinct characters remain
            while (distinct > 2) {
                if (--counts[(unsigned char)s[left++]] == 0) distinct--;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
