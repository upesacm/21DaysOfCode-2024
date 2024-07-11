#include<iostream>
#include<string>
using namespace std;

bool isSymmetrical(string s){

    char test[s.size()];

    for(int i = 0; i < s.size(); i++)
        test[s.size() - 1 - i] = char(25 - int(s[i]) + 2*int('a'));

    cout << test << endl;    

    for(int i = 0; i < s.size(); i++){

        if(s[i] != test[i])
            return false;
    }      

    return true;

    
}

int main(){

    cout << isSymmetrical("bazy") << endl;
}