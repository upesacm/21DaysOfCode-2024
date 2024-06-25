#include<iostream>
#include<set>
using namespace std;

bool isPalindrome(string temp){

    for(int i = 0; i < temp.size()/2; i++){

        if(temp[i] != temp[temp.size() - 1- i])
            return false;
    }
    
    return true;
}

int makeSubstring(string s, int k){

    set<string> palindromes;

    for(int i = 0; i <= s.size() - k; i++){

        string temp = s.substr(i, k);

        if(isPalindrome(temp))
            palindromes.insert(temp);
    }

    return palindromes.size();
}

