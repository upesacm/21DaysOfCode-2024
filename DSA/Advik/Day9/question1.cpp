#include <bits/stdc++.h>
#include <vector>

struct customstack{
    vector<int> values;
    int max=0;
    int get_max(){
        for(int i=0;i<values.size();i++){
            if(max<values[i]) max=values[i];
        }
        return max;
    }
    void push(int num){
    if(num){
         values.push_back(num);
    }
    
    }
    void pop(){
    if(values.size()!=0){
        values.pop_back();
    }
    }
    customstack(int maxsize){
        max=maxsize;
    }
    
    

};




int main(){
    
    customstack x(4);
    x.push(9);
     x.push(4);
      x.push(4);
       x.push(10);
       x.pop();
    cout<<x.get_max();
    
}