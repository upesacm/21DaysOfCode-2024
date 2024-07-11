#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int divisibleSumPairs(std::vector<int> nums, int k) {
    unordered_map<int, int> count;
    int pairs = 0;
    for (int num : nums) {
        int remainder = num % k;
        pairs += count[(k - remainder) % k];
        count[remainder]++;
    }
    return pairs;
}

int main() {
    int n;
    cout << "Enter size : ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k;
    cout << "Enter value of k : ";
    cin >> k;
    cout << "Output = " << divisibleSumPairs(nums, k);
}