#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq; // for creating min priority queue

void insert(int data) {
    pq.push(data);
}

int extract_min() {
    if (pq.empty()) {
        cout << "Priority queue is empty" << endl;
        return -1;
    }
    int minVal = pq.top();
    pq.pop();
    return minVal;
}

int main() {
    insert(4);
    insert(2);
    cout << extract_min() << endl;
    cout << extract_min() << endl; 
    cout << extract_min() << endl;
    return 0;
}