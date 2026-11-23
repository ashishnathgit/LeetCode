// Difficulty: Medium | Time: O(log n) update/query | Space: O(n) | Pattern: Design | Use: Real-time prefix aggregates and mutable range analytics (Fenwick tree)
class NumArray {
public:
    NumArray(vector<int>& nums) : vals(nums), tree(nums.size() + 1, 0), n(nums.size()) {
        // Build Fenwick tree in O(n) by propagating each node's value to its parent
        for (int i = 1; i <= n; ++i) {
            tree[i] += nums[i - 1];
            int parent = i + (i & -i);
            if (parent <= n) tree[parent] += tree[i];
        }
    }

    void update(int index, int val) {
        int delta = val - vals[index];
        vals[index] = val;
        for (int i = index + 1; i <= n; i += i & -i) {
            tree[i] += delta;
        }
    }

    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }

private:
    vector<int> vals;
    vector<int> tree;
    int n;

    int prefixSum(int i) const {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
