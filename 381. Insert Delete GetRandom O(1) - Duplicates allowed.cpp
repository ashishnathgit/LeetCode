// Difficulty: Hard | Time: O(1) avg | Space: O(n) | Pattern: Design | Use: Weighted-frequency O(1) random sampling over dynamic multisets
class RandomizedCollection {
public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool isNew = idxMap[val].empty();
        idxMap[val].insert(vals.size());
        vals.push_back(val);
        return isNew;
    }

    bool remove(int val) {
        auto it = idxMap.find(val);
        if (it == idxMap.end() || it->second.empty()) return false;

        int idx = *it->second.begin();
        it->second.erase(idx);
        int lastIdx = (int)vals.size() - 1;
        if (idx != lastIdx) {
            int lastVal = vals.back();
            vals[idx] = lastVal;
            idxMap[lastVal].erase(lastIdx);
            idxMap[lastVal].insert(idx);
        }
        vals.pop_back();
        if (it->second.empty()) idxMap.erase(it);
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }

private:
    vector<int> vals;
    unordered_map<int, unordered_set<int>> idxMap;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
