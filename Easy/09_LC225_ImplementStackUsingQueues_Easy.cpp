// LeetCode 225 - Implement Stack using Queues
// Question: Implement a last-in-first-out stack using only queue operations.
// Approach: After push, rotate the queue so the newest value is at the front.
// Push: O(n) | Pop: O(1) | Top: O(1) | Space: O(n)

class MyStack {
private:
    queue<int> q;

public:
    MyStack() = default;

    void push(int x) {
        q.push(x);
        int count = (int)q.size();
        for (int i = 0; i < count - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int value = q.front();
        q.pop();
        return value;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
