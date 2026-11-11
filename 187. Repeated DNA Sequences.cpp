class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.size() < 10) return result;

        // Encode each letter in 2 bits, so a 10-letter window fits in a 20-bit integer
        auto encode = [](char c) {
            switch (c) {
                case 'A': return 0;
                case 'C': return 1;
                case 'G': return 2;
                default:  return 3;  // 'T'
            }
        };

        const int mask = (1 << 20) - 1;
        unordered_map<int, int> seen;  // window code -> times seen
        int code = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            // Slide the window: shift in the new letter, drop the oldest one
            code = ((code << 2) | encode(s[i])) & mask;

            // Report a sequence only the second time we see it
            if (i >= 9 && ++seen[code] == 2) {
                result.push_back(s.substr(i - 9, 10));
            }
        }
        return result;
    }
};
