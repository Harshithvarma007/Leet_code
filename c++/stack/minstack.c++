class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> minStack;

public:
    MinStack() {
        // Nothing specific needed here since stacks are already initialized.
    }

    void push(int val) {
        stack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (!stack.empty()) {
            if (stack.top() == minStack.top()) {
                minStack.pop();
            }
            stack.pop();
        }
    }

    int top() {
        if (!stack.empty()) {
            return stack.top();
        }
        return -1; // Handle empty stack case
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1; // Handle empty stack case
    }
};
