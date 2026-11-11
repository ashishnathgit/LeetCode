class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Remember where each character was last seen (0 = never).
        // Matching pairs must always have been last seen at the same position.
        int lastS[256] = {0}, lastT[256] = {0};

        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char a = s[i], b = t[i];
            if (lastS[a] != lastT[b]) return false;
            lastS[a] = lastT[b] = i + 1;
        }
        return true;
    }
};
