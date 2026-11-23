// Difficulty: Medium | Time: O(1) avg | Space: O(n) | Pattern: Design | Use: O(1) uniform random sampling with dynamic insertions and deletions
class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (idxMap.count(val)) return false;
        idxMap[val] = vals.size();
        vals.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = idxMap.find(val);
        if (it == idxMap.end()) return false;

        int idx = it->second;
        int last = vals.back();
        vals[idx] = last;
        idxMap[last] = idx;
        vals.pop_back();
        idxMap.erase(it);
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }

private:
    vector<int> vals;
    unordered_map<int, int> idxMap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
