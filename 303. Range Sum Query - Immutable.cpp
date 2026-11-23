// Difficulty: Easy | Time: O(n) build, O(1) query | Space: O(n) | Pattern: Design | Use: Fast immutable range aggregations in analytics and time-series
class NumArray {
public:
    NumArray(vector<int>& nums) : prefix(nums.size() + 1, 0) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }

private:
    vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
