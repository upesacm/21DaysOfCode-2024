#include <iostream>
#include <unordered_set>
using namespace std;

string canSegment(string s, unordered_set<string>& dict) {
    if (s.empty()) return "YES";
    for (int i = 1; i <= s.size(); i++) {
        string prefix = s.substr(0, i);
        if (dict.find(prefix) != dict.end() && canSegment(s.substr(i), dict) == "YES") {
            return "YES";
        }
    }
    return "NO";
}

int main() {
    string s;
    getline(cin,s);
    unordered_set<string> dict;
    int n;
    cout << "Enter dictionery size : ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str;
        getline(cin,str);
        dict.insert(str);
    }
    cout << canSegment(s, dict);
}
