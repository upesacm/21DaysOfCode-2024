/*
Question 1: A function to determine if a given sentence includes every letter of the English alphabet at least once. The function should be case insensitive and return "complete" if the sentence contains every letter, otherwise return "incomplete".

Inputs:
A string representing the sentence.
Output:
"complete" if the sentence is a pangram, otherwise "incomplete".
Example:
sentence = "The quick brown fox jumps over the lazy dog"
*/
#include<iostream>
#include<string>
#include<set>
using namespace std;

bool checkPangram(string& str){
    set<char> set;
    for(auto ch:str){
        if (ch >= 'a' and ch<='z')
        set.insert(ch);

        if (ch>='A' and ch<= 'z'){
            ch = tolower(ch);
            set.insert(ch);
        }
    }

    return set.size()==26;
}

int main(){
    string str = "The quick brown fox jumps over the lazy dog blahh";
    if (checkPangram(str)== true)
    cout<<"Complete"<<endl;
    else   
    cout<<"Incomplete"<<endl;

    return 0;
}