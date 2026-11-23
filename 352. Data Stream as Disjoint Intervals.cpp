// Difficulty: Hard | Time: O(log n) add, O(n) get | Space: O(n) | Pattern: Design | Use: Coalescing contiguous IP ranges, memory blocks, or timestamps
class SummaryRanges {
public:
    SummaryRanges() {}

    void addNum(int value) {
        auto it = intervals.upper_bound(value);
        int start = value, end = value;

        if (it != intervals.begin()) {
            auto prevIt = prev(it);
            if (prevIt->second >= value) return;  // Already covered
            if (prevIt->second + 1 == value) {
                start = prevIt->first;
                intervals.erase(prevIt);
            }
        }
        if (it != intervals.end() && value + 1 == it->first) {
            end = it->second;
            intervals.erase(it);
        }
        intervals[start] = end;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        res.reserve(intervals.size());
        for (const auto& [start, end] : intervals) {
            res.push_back({start, end});
        }
        return res;
    }

private:
    map<int, int> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
