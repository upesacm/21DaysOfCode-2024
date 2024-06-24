#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int noOfPalindromeSubstrings(string& str, int k) {
        int n = str.length();
        unordered_set<string> palindromicSubstrings;
        
        if (k > n) {
            return 0;
        }

        for (int i = 0; i <= n - k; i++) {
            if (isPalindrome(str, i, i + k - 1)) {
                palindromicSubstrings.insert(str.substr(i, k));
            }
        }

        return palindromicSubstrings.size();
    }

private:
    bool isPalindrome(const string& str, int start, int end) {
        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    string str;
    cout << "Enter a string" << endl;
    getline(cin, str);
    cout << "Enter the length of substrings" << endl;
    int k;
    cin >> k;
    Solution sol;
    int result = sol.noOfPalindromeSubstrings(str, k);
    cout << "The number of distinct palindromic substrings in the given string is/are: " << result << endl;
    return 0;
}
