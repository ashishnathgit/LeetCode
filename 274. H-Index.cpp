// Difficulty: Medium | Time: O(n) | Space: O(n) | Pattern: Counting Sort | Use: Researcher impact metrics and popularity thresholds
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        // Bucket papers by citation count, capping at n
        vector<int> buckets(n + 1, 0);
        for (int c : citations) buckets[min(c, n)]++;

        // Walk from the top: first h with at least h papers having >= h citations
        int papers = 0;
        for (int h = n; h >= 0; --h) {
            papers += buckets[h];
            if (papers >= h) return h;
        }
        return 0;
    }
};
