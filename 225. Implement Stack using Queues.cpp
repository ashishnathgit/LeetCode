// Difficulty: Easy | Time: O(n) push, O(1) others | Space: O(n) | Pattern: Design + Queue | Use: Adapting data structure interfaces
class MyStack {
    queue<int> q;
public:
    MyStack() {}

    void push(int x) {
        // Rotate so the newest element sits at the front.
        q.push(x);
        for (int i = 0; i + 1 < (int)q.size(); ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};
