// Difficulty: Hard | Time: O(n) | Space: O(n) | Pattern: Stack | Use: Expression evaluation in calculators and interpreters
class Solution {
public:
    int calculate(string s) {
        // Stack saves (result, sign) before each '('.
        stack<int> st;
        long long result = 0, num = 0;
        int sign = 1;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= st.top(); st.pop();
                result += st.top(); st.pop();
            }
        }
        return result + sign * num;
    }
};
