class Solution {
public:
    int titleToNumber(string columnTitle) {
        // Base 26 where A = 1 ... Z = 26
        int result = 0;
        for (char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};
