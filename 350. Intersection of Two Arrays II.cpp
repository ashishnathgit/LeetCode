// Difficulty: Easy | Time: O(n + m) | Space: O(min(n, m)) | Pattern: Hash Map | Use: Multiset join preserving multiplicity across two streams
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);

        unordered_map<int, int> freq;
        for (int x : nums1) ++freq[x];

        vector<int> result;
        for (int x : nums2) {
            auto it = freq.find(x);
            if (it != freq.end() && it->second > 0) {
                result.push_back(x);
                --it->second;
            }
        }
        return result;
    }
};
