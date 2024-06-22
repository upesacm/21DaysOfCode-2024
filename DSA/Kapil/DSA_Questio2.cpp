//here is my solution to the 2nd question
#include <iostream>
#include <vector>

using namespace std;

int count_valid_pairs(vector<int>& arr, int k) {
  int count = 0;
  vector<int> remainders(k, 0);
  for (int num : arr) {
    int remainder = num % k;
    count += (remainder == 0) ? remainders[0] : remainders[(k - remainder) % k];
    remainders[remainder]++;
  }
  return count;
}

int main() {
  vector<int> arr = {1, 3, 2, 6, 1, 2};
  int k = 3;

  int valid_pairs = count_valid_pairs(arr, k);
  cout << "Number of valid pairs: " << valid_pairs << endl;

  return 0;
}
