//Question 2
#include <iostream>
#include <vector>
using namespace std;

int countDivisiblePairs(const vector<int>& arr, int k) {
    int count = 0;
    int n = arr.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((arr[i] + arr[j]) % k == 0) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << "Enter the value of k: ";
    cin >> k;
    
    int result = countDivisiblePairs(arr, k);
    cout << "Number of valid pairs: " << result << endl;
    
    return 0;
}
