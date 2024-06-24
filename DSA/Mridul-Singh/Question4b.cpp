# include<bits/stdc++.h>
using namespace std;

//This is the simple approach using map in c++ Time Complexity -> O(n)
string checkCriteria(string str){
    unordered_map <int,int> mp;
    for(int i=0;i<str.size();i++){
        mp[str[i]]++;
    }
    unordered_map <int ,int> frequencyCount;
    for(auto i=mp.begin();i!=mp.end();i++){
        frequencyCount[i->second]++;
    }
    if (frequencyCount.size() == 1) {
        return "valid";
    }
    if (frequencyCount.size() == 2) {
        auto it = frequencyCount.begin();
        int freq1 = it->first;
        int count1 = it->second;
        ++it;
        int freq2 = it->first;
        int count2 = it->second;
        if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
            return "valid";
        }
        if ((abs(freq1 - freq2) == 1) && ((count1 == 1 && freq1 > freq2) || (count2 == 1 && freq2 > freq1))) {
            return "valid";
        }
    }
    return "Invalid";
}

int main(){
    string str="aabbcc";
    cout << checkCriteria(str);
    return 0;
}