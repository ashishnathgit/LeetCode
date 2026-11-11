// Difficulty: Medium | Time: O(1) per op | Space: O(capacity) | Pattern: Design | Use: Caches in CDNs, databases and browsers
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = positions.find(key);
        if (it == positions.end()) return -1;

        // Move to the front: most recently used
        items.splice(items.begin(), items, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = positions.find(key);
        if (it != positions.end()) {
            it->second->second = value;
            items.splice(items.begin(), items, it->second);
            return;
        }

        // Full: evict the least recently used item from the back
        if ((int)items.size() == capacity) {
            positions.erase(items.back().first);
            items.pop_back();
        }

        items.emplace_front(key, value);
        positions[key] = items.begin();
    }

private:
    int capacity;
    list<pair<int, int>> items;  // {key, value}, front = most recently used
    unordered_map<int, list<pair<int, int>>::iterator> positions;  // key -> node in items
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
