#include<iostream>
#include<vector>
using namespace std;

int no_of_pairs(vector<int> arr, int k){

    int count = 0;

    for(int i = 0; i < arr.size(); i++){

        for(int j = i + 1; j < arr.size(); j++){

            if((arr[i] + arr[j]) % k == 0)
                count++;
        }
    }

    return count;
}

int main(){

    cout << no_of_pairs({1, 3, 2, 6, 1, 2}, 3);
}