#include <iostream>
#include <string>

using namespace std;

bool isSymmetrical(const string& str) {
  int len = str.length();
  for (int i = 0; i < len / 2; ++i) {
    if (static_cast<int>(str[i]) != static_cast<int>(str[len - i - 1])) {
      return false;
    }
  }
  return true;
}

int main() {
  string input;

  cout << "Enter a string: ";
  getline(cin, input);

  if (isSymmetrical(input)) {
    cout << "symmetrical" << endl;
  } else {
    cout << "not symmetrical" << endl;
  }

  return 0;
}
