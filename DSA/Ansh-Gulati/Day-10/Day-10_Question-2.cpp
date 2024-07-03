#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> stack1;
    stack<int> stack2;

    void moveStack1ToStack2()
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    void enqueue(int data)
    {
        stack1.push(data);
    }

    int dequeue()
    {
        if (stack2.empty())
        {
            if (stack1.empty())
            {
                throw out_of_range("Queue is empty");
            }
            moveStack1ToStack2();
        }
        int topVal = stack2.top();
        stack2.pop();
        return topVal;
    }

    void printQueue()
    {
        if (stack2.empty())
        {
            moveStack1ToStack2();
        }
        stack<int> temp = stack2;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Queue: ";
    q.printQueue();

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Queue: ";
    q.printQueue();

    return 0;
}
