// Difficulty: Easy | Time: O(1) amortized | Space: O(n) | Pattern: Design + Stack | Use: Building FIFO buffers from LIFO primitives
class MyQueue {
    stack<int> in, out;
    void shift() {
        if (out.empty())
            while (!in.empty()) { out.push(in.top()); in.pop(); }
    }
public:
    MyQueue() {}

    void push(int x) { in.push(x); }

    int pop() {
        shift();
        int x = out.top();
        out.pop();
        return x;
    }

    int peek() {
        shift();
        return out.top();
    }

    bool empty() { return in.empty() && out.empty(); }
};
