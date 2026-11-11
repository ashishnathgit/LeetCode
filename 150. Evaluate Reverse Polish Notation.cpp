// Difficulty: Medium | Time: O(n) | Space: O(n) | Pattern: Stack | Use: Expression evaluation in calculators, compilers and VMs
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            bool isOperator = token.size() == 1 && string("+-*/").find(token[0]) != string::npos;
            if (!isOperator) {
                st.push(stoi(token));
                continue;
            }

            // The right operand is on top
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            switch (token[0]) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;  // C++ division truncates toward zero
            }
        }
        return st.top();
    }
};
