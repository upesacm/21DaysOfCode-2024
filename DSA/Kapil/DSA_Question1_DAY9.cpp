#include <iostream>
#include <stack>

using namespace std;

class MaxStack {
private:
    stack<int> data_stack;
    stack<int> max_stack;
public:
    void push(int x) {
        data_stack.push(x);
        if (max_stack.empty() || x >= max_stack.top()) {
            max_stack.push(x);
        }
    }
    void pop() {
        if (!data_stack.empty()) {
            if (data_stack.top() == max_stack.top()) {
                max_stack.pop();
            }
            data_stack.pop();
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
    cout << "Max element after pushing 2: " << stack.get_max() << endl;
    stack.pop();
    cout << "Max element after popping: " << stack.get_max() << endl;
    return 0;
}
