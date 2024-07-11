#include <iostream>
#include <set>
#include <string>

using namespace std;

int countDistinctPalindromes(const string& str, int length) {
  set<string> seen;
  for (int i = 0; i <= str.size() - length; ++i) {
    string substring = str.substr(i, length);
    if (substring == string(substring.rbegin(), substring.rend())) {
      seen.insert(substring);
    }
  }
  return seen.size();
}

int main() {
  string str;
  int length;

  cout << "Enter a string: ";
  getline(cin, str);

  cout << "Enter the length of substrings (positive integer): ";
  cin >> length;

  if (length <= 0) {
    cout << "Invalid length. Please enter a positive integer." << endl;
    return 1;
  }

  int distinct_palindromes = countDistinctPalindromes(str, length);
  cout << "Number of distinct palindromic substrings of length " << length << ": " << distinct_palindromes << endl;
  return 0;
}
