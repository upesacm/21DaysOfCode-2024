#include<iostream>
#include<stack>
using namespace std;

class queue {
    private :
        stack<int> stk1;
        stack<int> stk2;
    public :
        void enqueue(int data) {
            stk1.push(data);
        }
        void dequeue() {
            if(stk2.empty()) {
                if(stk1.empty()) {
                    cout << "Underflow";
                }
                while(!stk1.empty()) {
                    stk2.push(stk1.top());
                    stk1.pop();
                }
            }
            cout << stk2.top() << " ";
            stk2.pop();
        }
};

int main() {
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.dequeue();
}
