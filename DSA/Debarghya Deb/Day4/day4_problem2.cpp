#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(string input ){
    map <int, int> umap;
    
    int min = 1000000000;
    for(int i = 0; i < input.size(); i++){
       
        umap[input[i]]++;
       
        
    }

    for(auto x : umap){
        if(x.second < min){
            min = x.second;
        }
    }

    for (auto x : umap){
        if(x.second > min + 1){
            return false;
        }

    }

    return true;
}

int main(){
    string input;
    cout<< "Enter the string : "  ;
    getline(cin, input);
    
    input.erase(remove(input.begin(), input.end(),' '),input.end());

     if(check(input)){
       
        cout<<"Valid" << endl;
     } 
     else{
        cout<< "Invalid" << endl;
     }
    



    

    return 0;
}