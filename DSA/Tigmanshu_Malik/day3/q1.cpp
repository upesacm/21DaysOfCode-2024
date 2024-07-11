#include<iostream>
#include<string>
using namespace std;

bool isComplete(string s){

    bool map[26] = {false} ;

    for(int i = 0; i < s.size(); i++){

        if('A' <= s[i] && s[i] <= 'Z')
            s[i] += 32;

        map[s[i] - 'a'] = true;    
    }

    for(int i = 0; i < 26; i++){

        if(map[i] == false)
            return false;
    }

    return true;

}

int main(){

    cout << isComplete("The quick brown fox jumps over the lazy dog");
}

