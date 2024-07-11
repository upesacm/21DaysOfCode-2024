#include <iostream>
#include <unordered_map>

using namespace std;

string isRearrangeable(const string& str) {
    
  unordered_map<char, int> char_counts;
  for (char c : str) {
    char_counts[c]++;
  }

  int odd_count = 0;
  for (auto it : char_counts) {
    if (it.second % 2 != 0) {
      odd_count++;
      if (odd_count > 1) {
        return "invalid";
      }
    }
  }

  return "valid";
}

int main() {
  string str;
  cout << "Enter a string: ";
  cin >> str;

  string result = isRearrangeable(str);
  cout << result << endl;
  return 0;
}
