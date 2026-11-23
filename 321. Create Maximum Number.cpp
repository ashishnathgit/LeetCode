// Difficulty: Hard | Time: O(k·(n + m + k²)) | Space: O(k) | Pattern: Greedy | Use: Merging constrained maximum subsequences across two streams
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> best;

        int lo = max(0, k - n2), hi = min(k, n1);
        for (int i = lo; i <= hi; ++i) {
            vector<int> candidate = merge(pickMax(nums1, i), pickMax(nums2, k - i));
            if (candidate > best) best = std::move(candidate);
        }
        return best;
    }

private:
    vector<int> pickMax(const vector<int>& nums, int k) {
        vector<int> st;
        int drop = (int)nums.size() - k;
        for (int x : nums) {
            while (!st.empty() && drop > 0 && st.back() < x) {
                st.pop_back();
                --drop;
            }
            st.push_back(x);
        }
        st.resize(k);
        return st;
    }

    bool greaterSuffix(const vector<int>& a, int i, const vector<int>& b, int j) {
        while (i < (int)a.size() && j < (int)b.size() && a[i] == b[j]) {
            ++i;
            ++j;
        }
        return j == (int)b.size() || (i < (int)a.size() && a[i] > b[j]);
    }

    vector<int> merge(const vector<int>& a, const vector<int>& b) {
        vector<int> res;
        res.reserve(a.size() + b.size());
        int i = 0, j = 0;
        while (i < (int)a.size() || j < (int)b.size()) {
            res.push_back(greaterSuffix(a, i, b, j) ? a[i++] : b[j++]);
        }
        return res;
    }
};
