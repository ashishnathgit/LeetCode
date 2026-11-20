class Solution {
public:
    int uniqueLetterString(string s) {
        int lastTwo[26][2];
        for (int i = 0; i < 26; ++i) {
            lastTwo[i][0] = -1;
            lastTwo[i][1] = -1;
        }

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'A';
            int prev = lastTwo[c][0];
            int curr = lastTwo[c][1];

            if (curr != -1) {
                total += (curr - prev) * (i - curr);
            }

            lastTwo[c][0] = curr;
            lastTwo[c][1] = i;
        }

        for (int c = 0; c < 26; ++c) {
            int prev = lastTwo[c][0];
            int curr = lastTwo[c][1];
            if (curr != -1) {
                total += (curr - prev) * (n - curr);
            }
        }

        return total;
    }
};

