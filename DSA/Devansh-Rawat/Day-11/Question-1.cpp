#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class PriorityQueue {
public:
    PriorityQueue() {}
    void insert(int element) {
        heap.push_back(element);
        siftUp(heap.size() - 1);
    }
    int extractMin() {
        if (heap.empty()) {
            throw out_of_range("Priority queue is empty");
        }
        int minElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            siftDown(0);
        }
        return minElement;
    }
    int getMin() const {
        if (heap.empty()) {
            throw out_of_range("Priority queue is empty");
        }
        return heap[0];
    }
    bool isEmpty() const {
        return heap.empty();
    }
private:
    vector<int> heap;
    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] >= heap[parent]) {
                break;
            }
            std::swap(heap[i], heap[parent]);
            i = parent;
        }
    }
    void siftDown(int i) {
        int leftChild, rightChild, smallest, n = heap.size();
        while (true) {
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
            smallest = i;
            if (leftChild < n && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < n && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest == i) {
                break;
            }
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }
};
int main() {
    PriorityQueue pq;
    pq.insert(3);
    pq.insert(1);
    pq.insert(4);
    pq.insert(1);
    pq.insert(5);
    pq.insert(9);
    cout << "Extracting minimum elements:" << endl;
    while (!pq.isEmpty()) {
        cout << pq.extractMin() << " ";
    }
    cout << endl;
    return 0;
}
