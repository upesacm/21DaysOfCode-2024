#include <bits/stdc++.h>

using namespace std;

string canBeEqualizedByOneRemoval(const string &s) {
    int charFrequency[26] = {0}; 
    int frequencyCount[101] = {0}; 

    for (char c : s) {
        charFrequency[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (charFrequency[i] > 0) {
            frequencyCount[charFrequency[i]]++;
        }
    }

    int uniqueFrequencies[2] = {0}; 
    int freqCounts[2] = {0}; 
    int index = 0;

    for (int i = 1; i <= 100; i++) {
        if (frequencyCount[i] > 0) {
            if (index < 2) {
                uniqueFrequencies[index] = i;
                freqCounts[index] = frequencyCount[i];
                index++;
            } else {
                return "invalid"; 
            }
        }
    }

    if (index == 1) {
        return "valid";
    }

    int freq1 = uniqueFrequencies[0];
    int count1 = freqCounts[0];
    int freq2 = uniqueFrequencies[1];
    int count2 = freqCounts[1];

    if (freq1 > freq2) {
        swap(freq1, freq2);
        swap(count1, count2);
    }
    if ((freq1 == 1 && count1 == 1) || (freq2 == freq1 + 1 && count2 == 1)) {
        return "valid";
    }

    return "invalid";
}

int main() {
    vector<string> testStrings = {
        "aabbcc",  
        "aabbccc", 
        "aabbcccc", 
        "aabbc",   
        "aabb",    
        "aabcdd",  
        "abcd"     
    };

    for (const string &s : testStrings) {
        cout << "Result for \"" << s << "\": " << canBeEqualizedByOneRemoval(s) << endl;
    }

    return 0;
}
