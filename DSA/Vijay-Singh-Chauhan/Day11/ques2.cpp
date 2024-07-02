#include<bits/stdc++.h>
using namespace std;

void insert(priority_queue<int,vector<int>,greater<int>>& min_heap, int num){
    cout<<"Inserted: "<<num<<endl;
    min_heap.push(num);
}
void extract_min(priority_queue<int,vector<int>,greater<int>>& min_heap,int min_num){
    if(min_heap.empty()){
        cout<<"Empty"<<endl;
    }
    cout<<"Minheap: "<<min_heap.top()<<endl;
    cout<<"pop top min value....."<<endl;
    min_heap.pop();
}

int main(){
    int min_num;
    priority_queue<int, vector<int>,greater<int>>min_heap;
 
    insert(min_heap,4);
    insert(min_heap,2);
    
    extract_min(min_heap,min_num);
    extract_min(min_heap,min_num);
   
}
