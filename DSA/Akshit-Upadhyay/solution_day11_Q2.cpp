#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
  vector<pair<int, int>> data;

  void swap(int i, int j) {
    pair<int, int> temp = data[i];
    data[i] = data[j];
    data[j] = temp;
  }

  void siftUp(int index) {
    while (index > 0 && data[index].first < data[(index - 1) / 2].first) {
      swap(index, (index - 1) / 2);
      index = (index - 1) / 2;
    }
  }

  void siftDown(int index) {
    while (2 * index + 1 < data.size()) {
      int childIndex = 2 * index + 1;
      if (childIndex + 1 < data.size() && data[childIndex].first > data[childIndex + 1].first) {
        childIndex++;
      }
      if (data[index].first <= data[childIndex].first) {
        break;
      }
      swap(index, childIndex);
      index = childIndex;
    }
  }

public:
  void insert(int priority, int value) {
    data.push_back({priority, value});
    siftUp(data.size() - 1);
  }

  pair<int, int> extractMin() {
    if (isEmpty()) {
      throw runtime_error("Priority queue is empty");
    }
    pair<int, int> min = data[0];
    data[0] = data.back();
    data.pop_back();
    siftDown(0);
    return min;
  }

  bool isEmpty() const {
    return data.empty();
  }
};

int main() {
  PriorityQueue pq;
  pq.insert(4, 2);  
  pq.insert(2, 1); 
  pq.insert(5, 3);
  
  pair<int, int> min = pq.extractMin();
  cout << "Extracted minimum: priority " << min.first << ", value " << min.second << endl; 

  min = pq.extractMin();
  cout << "Extracted minimum: priority " << min.first << ", value " << min.second << endl; 

  return 0;
}
