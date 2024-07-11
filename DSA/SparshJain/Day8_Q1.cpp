#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int max_equal_height(vector<int>& stack1, vector<int>& stack2, vector<int>& stack3) {
    int sum1 = accumulate(stack1.begin(), stack1.end(), 0);
    int sum2 = accumulate(stack2.begin(), stack2.end(), 0);
    int sum3 = accumulate(stack3.begin(), stack3.end(), 0);
    int i = 0, j = 0, k = 0;
    
    while (!(sum1 == sum2 && sum1 == sum3)) {
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= stack1[i++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= stack2[j++];
        } else {
            sum3 -= stack3[k++];
        }
    }
    return sum1;
}

int main() {
    vector<int> stack1 = {3, 2, 1, 1, 1};
    vector<int> stack2 = {4, 3, 2};
    vector<int> stack3 = {1, 1, 4, 1};

    cout << max_equal_height(stack1, stack2, stack3) << endl;
    return 0;
}
