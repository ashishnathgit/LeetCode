// Difficulty: Hard | Time: O(log n) add, O(1) median | Space: O(n) | Pattern: Heap | Use: Streaming percentile and latency tracking
class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        // Push to max-heap, rebalance through min-heap so lower holds >= upper
        lower.push(num);
        upper.push(lower.top());
        lower.pop();
        if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }

    double findMedian() {
        if (lower.size() > upper.size()) return lower.top();
        return ((double)lower.top() + upper.top()) / 2.0;
    }

private:
    priority_queue<int> lower;                             // Smaller half (max-heap)
    priority_queue<int, vector<int>, greater<int>> upper;  // Larger half (min-heap)
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
