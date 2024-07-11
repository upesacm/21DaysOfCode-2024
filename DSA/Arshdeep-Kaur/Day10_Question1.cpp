#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int front = q.front();
    q.pop();

    reverseQueue(q);
    q.push(front);
}

int main()
{
    queue<int> q;
    int n, element;

    cout << "Enter the number of elements in the queue: ";
    cin >> n;

    cout << "Enter the elements of the queue: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> element;
        q.push(element);
    }

    cout << "Original queue: ";
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    reverseQueue(q);

    cout << "Reversed queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
