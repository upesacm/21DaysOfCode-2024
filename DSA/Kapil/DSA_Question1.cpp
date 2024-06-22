//here is the solution of the question 1
#include <iostream>

using namespace std;

int count_valid_segments(int candy[], int day, int n, int month) {
  int count = 0;
  int current_sum = 0;
  int start = 0;

  for (int i = 0; i < n; i++) {
    current_sum += candy[i];

    if (i - start + 1 == month) {  
      if (current_sum == day) {  
        count++;
      }
      start++;  
      current_sum -= candy[start - 1];  
    }
  }

  return count;
}

int main() {
  int candy[] = {2, 2, 1, 3, 2};
  int day = 4;
  int month = 2;
  int n = sizeof(candy) / sizeof(candy[0]);

  int valid_segments = count_valid_segments(candy, day, n, month);
  cout << "Number of valid segments: " << valid_segments << endl;

  return 0;
}
