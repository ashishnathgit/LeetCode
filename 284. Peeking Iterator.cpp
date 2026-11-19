// Difficulty: Medium | Time: O(1) per call | Space: O(1) | Pattern: Design | Use: Lookahead in tokenizers and stream parsers
/*
 * Below is the interface for Iterator, which is already defined for you.
 * class Iterator {
 *     struct Data;
 *     Data* data;
 * public:
 *     Iterator(const vector<int>& nums);
 *     Iterator(const Iterator& iter);
 *     int next();
 *     bool hasNext() const;
 * };
 */

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Pre-fetch one element so peek() is always ready
        hasCached = Iterator::hasNext();
        if (hasCached) cached = Iterator::next();
    }

    int peek() {
        return cached;
    }

    int next() {
        int result = cached;
        hasCached = Iterator::hasNext();
        if (hasCached) cached = Iterator::next();
        return result;
    }

    bool hasNext() const {
        return hasCached;
    }

private:
    int cached = 0;
    bool hasCached = false;
};
