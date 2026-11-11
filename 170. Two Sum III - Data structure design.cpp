class TwoSum {
public:
    TwoSum() {}

    void add(int number) {
        counts[number]++;
    }

    bool find(int value) {
        for (const auto& [num, count] : counts) {
            long long complement = (long long)value - num;

            if (complement == num) {
                // Using the same number twice needs it added at least twice
                if (count > 1) return true;
            } else if (complement >= INT_MIN && complement <= INT_MAX && counts.count((int)complement)) {
                return true;
            }
        }
        return false;
    }

private:
    unordered_map<int, int> counts;  // number -> how many times it was added
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
