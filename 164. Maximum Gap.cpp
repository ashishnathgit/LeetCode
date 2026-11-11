class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());
        int lo = *minIt, hi = *maxIt;
        if (lo == hi) return 0;

        // The max gap is at least (hi - lo) / (n - 1), so it can never sit inside one bucket.
        // We only need each bucket's min and max (bucket sort, O(n)).
        int bucketSize = max(1, (hi - lo) / (n - 1));
        int bucketCount = (hi - lo) / bucketSize + 1;
        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        for (int x : nums) {
            int b = (x - lo) / bucketSize;
            bucketMin[b] = min(bucketMin[b], x);
            bucketMax[b] = max(bucketMax[b], x);
        }

        // The answer is the largest jump from one non-empty bucket's max to the next one's min
        int best = 0, prevMax = lo;
        for (int b = 0; b < bucketCount; ++b) {
            if (bucketMin[b] == INT_MAX) continue;  // Empty bucket
            best = max(best, bucketMin[b] - prevMax);
            prevMax = bucketMax[b];
        }
        return best;
    }
};
