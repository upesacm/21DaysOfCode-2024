#include <iostream>
#include <vector>
#include <algorithm>

class PriorityQueue {
public:
    void insert(int value) {
        heap.push_back(value);
        std::push_heap(heap.begin(), heap.end(), std::greater<>());
    }

    int extract_min() {
        if (heap.empty()) {
            std::cerr << "Priority queue is empty" << std::endl;
            return -1;
        }
        std::pop_heap(heap.begin(), heap.end(), std::greater<>());
        int min = heap.back();
        heap.pop_back();
        return min;
    }

private:
    std::vector<int> heap;
};

int main() {
    PriorityQueue pq;
    pq.insert(4);
    pq.insert(2);
    std::cout << "Extracted min: " << pq.extract_min() << std::endl; // Output: 2
    pq.insert(5);
    std::cout << "Extracted min: " << pq.extract_min() << std::endl; // Output: 4
    std::cout << "Extracted min: " << pq.extract_min() << std::endl; // Output: 5
    return 0;
}
