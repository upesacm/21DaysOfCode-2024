
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string checkSymmetry(string str) {
     string reversed = str;
    for (char& c : reversed) {
        c = 'z' - (c - 'a');  
    }
    reverse(reversed.begin(), reversed.end());

     if (str == reversed) {
        return "symmetrical";
    } else {
        return "not symmetrical";
    }
}

int main() {
    string str;
    cout<<"Enter a Sentences: ";
    getline(cin,str);

    return 0;
}

