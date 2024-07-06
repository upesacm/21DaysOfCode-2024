#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapifyUp(int index)
{
    if (index == 0)
        return;
    int parentIndex = (index - 1) / 2;
    if (heap[parentIndex] > heap[index])
    {
        swap(heap[parentIndex], heap[index]);
        heapifyUp(parentIndex);
    }
}

void heapifyDown(int index)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
    {
        smallest = leftChild;
    }
    if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
    {
        smallest = rightChild;
    }
    if (smallest != index)
    {
        swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int extractMin()
{
    if (heap.empty())
    {
        cout << "Priority queue is empty" << endl;
        return -1;
    }
    int minValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty())
    {
        heapifyDown(0);
    }
    return minValue;
}

int main()
{
    insert(4);
    insert(2);
    cout << extractMin() << endl;
    cout << extractMin() << endl;

    return 0;
}