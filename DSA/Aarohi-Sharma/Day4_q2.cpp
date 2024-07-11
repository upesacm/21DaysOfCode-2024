#include <bits/stdc++.h>
using namespace std;
string isValid(string s) {
    unordered_map<char, int> freq;
    unordered_map<int, int> freqCount;
    for (char c : s) {
        freq[c]++;
    }
    for (auto& pair : freq) {
        freqCount[pair.second]++;
    }
    if (freqCount.size() == 1) {
        return "valid";
    } else if (freqCount.size() == 2) {
        auto it = freqCount.begin();
        int freq1 = it->first;
        int count1 = it->second;
        it++;
        int freq2 = it->first;
        int count2 = it->second;
        if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
            return "valid";
        }
        if ((abs(freq1 - freq2) == 1) && ((count1 == 1 && freq1 > freq2) || (count2 == 1 && freq2 > freq1))) {
            return "valid";
        }
    }
    return "invalid";
}
int main() {
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}
