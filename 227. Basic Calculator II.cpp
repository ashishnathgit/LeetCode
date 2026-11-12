// Difficulty: Medium | Time: O(n) | Space: O(1) | Pattern: Stack (Simulated) | Use: Operator-precedence parsing in expression engines
class Solution {
public:
    int calculate(string s) {
        // Keep the running sum of finished terms plus the current term (handles * and / precedence).
        long long sum = 0, last = 0, num = 0;
        char op = '+';
        for (int i = 0; i <= (int)s.size(); ++i) {
            char c = i < (int)s.size() ? s[i] : '+';
            if (c == ' ') continue;
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                continue;
            }
            if (op == '+') { sum += last; last = num; }
            else if (op == '-') { sum += last; last = -num; }
            else if (op == '*') last *= num;
            else last /= num;
            op = c;
            num = 0;
        }
        return sum + last;
    }
};
