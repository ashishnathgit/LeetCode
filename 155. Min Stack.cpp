// Difficulty: Medium | Time: O(1) per op | Space: O(n) | Pattern: Stack | Use: Undo stacks that track a running minimum
class MinStack {
public:
    MinStack() {}

    void push(int val) {
        // Store each value with the minimum of the stack up to that point
        int currentMin = st.empty() ? val : min(val, st.top().second);
        st.emplace(val, currentMin);
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;  // {value, min so far}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
