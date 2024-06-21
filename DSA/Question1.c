//this is the solution for the question 1 on day 1
#include <stdio.h>

int main() {
  int candy[] = {2, 2, 1, 3, 2}; 
  int day = 4; 
  int month = 2; 
  int n = sizeof(candy) / sizeof(candy[0]); 

  int count = 0; 
  int current_sum = 0; 
  int start_index = 0; 
  for (int i = 0; i < n; i++) {
    current_sum += candy[i]; 
    if (i - start_index + 1 == month) { 
      if (current_sum == day) { 
        count++; 
      }
      start_index++; 
      current_sum -= candy[start_index - 1]; 
    }
  }

  printf("Number of valid segments: %d\n", count);

  return 0;
}
