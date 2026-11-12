// Difficulty: Hard | Time: O(n) | Space: O(k) | Pattern: Bucketing + Sliding Window | Use: Near-duplicate detection in sensor/price streams
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        // Buckets of width valueDiff+1: two values in the same bucket are always close enough;
        // otherwise only the neighbouring buckets can hold a match.
        long long w = (long long)valueDiff + 1;
        auto bucketOf = [&](long long x) { return x >= 0 ? x / w : (x + 1) / w - 1; };
        unordered_map<long long, long long> buckets;
        for (int i = 0; i < (int)nums.size(); ++i) {
            long long x = nums[i], id = bucketOf(x);
            if (buckets.count(id)) return true;
            if (buckets.count(id - 1) && x - buckets[id - 1] <= valueDiff) return true;
            if (buckets.count(id + 1) && buckets[id + 1] - x <= valueDiff) return true;
            buckets[id] = x;
            if (i >= indexDiff) buckets.erase(bucketOf(nums[i - indexDiff]));
        }
        return false;
    }
};
