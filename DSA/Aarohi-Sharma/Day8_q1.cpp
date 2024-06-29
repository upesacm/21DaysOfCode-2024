#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int findMaxEqualHeight(std::vector<int>& stack1, std::vector<int>& stack2, std::vector<int>& stack3) {
    int sum1 = accumulate(stack1.begin(), stack1.end(), 0);
    int sum2 = accumulate(stack2.begin(), stack2.end(), 0);
    int sum3 = accumulate(stack3.begin(), stack3.end(), 0);
    int i = 0, j = 0, k = 0;
    while (i < stack1.size() && j < stack2.size() && k < stack3.size()) {
        if (sum1 == sum2 && sum1 == sum3) {
            return sum1;
        }
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= stack1[i++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= stack2[j++];
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= stack3[k++];
        }
    }
    return 0;
}
int main() {
    vector<int> stack1 = {3, 2, 1, 1, 1};
    vector<int> stack2 = {4, 3, 2};
    vector<int> stack3 = {1, 1, 4, 1};
    int maxEqualHeight = findMaxEqualHeight(stack1, stack2, stack3);
    cout << "Maximum possible equal height: " << maxEqualHeight << std::endl;
    return 0;
}
