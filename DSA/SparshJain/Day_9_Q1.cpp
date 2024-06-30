#include <stack>
#include <iostream>
#include <algorithm>

class MaxStack {
private:
    std::stack<int> stack;
    std::stack<int> max_stack;

public:
    void push(int x) {
        stack.push(x);
        if (max_stack.empty() || x >= max_stack.top()) {
            max_stack.push(x);
        }
    }

    void pop() {
        if (!stack.empty()) {
            if (stack.top() == max_stack.top()) {
                max_stack.pop();
            }
            stack.pop();
        }
    }

    int get_max() {
        if (!max_stack.empty()) {
            return max_stack.top();
        }
        return -1; 
    }
};

int main() {
    MaxStack stack;
    stack.push(1);
    stack.push(2);
    std::cout << stack.get_max() << std::endl; 
    stack.pop();
    std::cout << stack.get_max() << std::endl; 
  return 0;
}
