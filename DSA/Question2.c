//this is the solution to 2nd question day 1
#include <stdio.h>
int count_valid_pairs(int arr[], int n, int k) {
  int count = 0;
  int seen[k] = {0}; 

  for (int i = 0; i < n; i++) {
    int remainder = arr[i] % k;
    int complement = (k - remainder) % k;

    count += seen[complement];

    seen[remainder]++;
  }

  return count;
}

int main() {
  int arr[] = {1, 3, 2, 6, 1, 2};
  int k = 3;
  int n = sizeof(arr) / sizeof(arr[0]);

  int valid_pairs = count_valid_pairs(arr, n, k);
  printf("Number of valid pairs: %d\n", valid_pairs);

  return 0;
}
