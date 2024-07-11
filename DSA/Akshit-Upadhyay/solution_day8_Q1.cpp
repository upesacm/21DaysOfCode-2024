#include <iostream>
#include <vector>

using namespace std;

int equalHeight(vector<int>& stack1, vector<int>& stack2, vector<int>& stack3) {

    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int h : stack1) sum1 += h;
    for (int h : stack2) sum2 += h;
    for (int h : stack3) sum3 += h;

    int i = 0, j = 0, k = 0;

    while (true) {

        if (i == stack1.size() || j == stack2.size() || k == stack3.size())
            return 0;

        if (sum1 == sum2 && sum1 == sum3)
            return sum1;

        if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= stack1[i++];
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= stack2[j++];
        else if (sum3 >= sum1 && sum3 >= sum2)
            sum3 -= stack3[k++];
    }
}

int main() {
    vector<int> stack1 = {3, 2, 1, 1, 1};
    vector<int> stack2 = {4, 3, 2};
    vector<int> stack3 = {1, 1, 4, 1};

    cout << equalHeight(stack1, stack2, stack3) << endl;

    return 0;
}
