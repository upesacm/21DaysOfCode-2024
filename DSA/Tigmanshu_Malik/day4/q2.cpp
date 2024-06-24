#include<iostream>
using namespace std;

bool checkFrequency(string s){

    char arr[26] = {0};
    int count, i = 0, j = 1;

    for(char i : s)
        arr[i - 'a']++;

    while(i < 25){

        if(arr[i] == 0)
            i++;

        else{
            
            while(arr[j] == 0 && j < 26)
                j++;

            if(j == 26)
                return true;    

            if(arr[i] == arr[j]){
                i = j;
                j = i + 1;
            }

            else if(arr[i] - arr[j] == 1 || arr[i] - arr[j] == -1){

                count++;

                if(count == 2)
                    return false;
                    

                i = j;
                j = i + 1;
            }

            else
                return false;
                 
        }
    }

    return true;
    
}
