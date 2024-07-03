#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class PriorityQueue {
private:
    
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    void insert(int item) {
        pq.push(item);
    }

    int extract_min() {
        if (pq.empty()) {
            cout<<"Priority Queue is empty" << endl;
            return -1;
        }
        int minItem = pq.top();
        pq.pop();
        return minItem;
    }


};

int main() {
    PriorityQueue priority_queue;
    priority_queue.insert(4);
    priority_queue.insert(2);

    
    cout << priority_queue.extract_min() << endl;  
    cout << priority_queue.extract_min() << endl;  
    

    return 0;
}
