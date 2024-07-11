#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
private:
    vector<int> heap;

    void heapifyUp(int index)
    {
        while (index > 0 && heap[index] < heap[(index - 1) / 2])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
        {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractMin()
    {
        if (heap.empty())
        {
            throw out_of_range("Heap is empty");
        }

        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minVal;
    }

    bool isEmpty()
    {
        return heap.empty();
    }
};

int main()
{
    PriorityQueue pq;
    pq.insert(4);
    pq.insert(2);

    cout << pq.extractMin() << endl; 
    cout << pq.extractMin() << endl; 

    return 0;
}
