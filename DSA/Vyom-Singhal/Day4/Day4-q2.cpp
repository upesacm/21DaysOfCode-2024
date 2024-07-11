#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string isValidString(string str) {
    unordered_map<char,int> storeCharFreq;
    for(char c : str) {
        storeCharFreq[c]++;
    }
    unordered_map<int,int> storeFreqFreq;
    for(auto& it : storeCharFreq) {
        storeFreqFreq[it.second]++;
    }
    if(storeFreqFreq.size() == 1) return "valid";
    if(storeFreqFreq.size() == 2) {
        auto it = storeFreqFreq.begin();
        int firstFreq = it->first, count1 = it->second;
        ++it;
        int secondFreq = it->first, count2 = it->second;
        if((firstFreq == 1 && count1 == 1) || (secondFreq == 1 && count2 == 1)) return "valid";
        if ((abs(firstFreq - secondFreq) == 1) && ((firstFreq > secondFreq && count1 == 1) || (secondFreq > firstFreq && count2 == 1))) return "valid";
    }
    return "invalid";
}

int main() {
    string str;
    cout << "Enter string : ";
    getline(cin,str);
    cout << isValidString(str);
}