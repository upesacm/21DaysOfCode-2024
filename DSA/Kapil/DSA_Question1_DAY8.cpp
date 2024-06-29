#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int maxEqualHeight(vector<int>& stack1, vector<int>& stack2, vector<int>& stack3) {
    // Calculate the initial heights of the stacks
    int height1 = accumulate(stack1.begin(), stack1.end(), 0);
    int height2 = accumulate(stack2.begin(), stack2.end(), 0);
    int height3 = accumulate(stack3.begin(), stack3.end(), 0);

    // Initialize pointers for each stack
    int idx1 = 0, idx2 = 0, idx3 = 0;

    // Loop until the heights of all stacks are equal
    while (true) {
        // If all heights are equal, return the height
        if (height1 == height2 && height1 == height3) {
            return height1;
        }

        // Find the tallest stack and remove the top cylinder
        if (height1 >= height2 && height1 >= height3) {
            height1 -= stack1[idx1++];
        } else if (height2 >= height1 && height2 >= height3) {
            height2 -= stack2[idx2++];
        } else {
            height3 -= stack3[idx3++];
        }
    }
}

int main() {
    vector<int> stack1 = {3, 2, 1, 1, 1};
    vector<int> stack2 = {4, 3, 2};
    vector<int> stack3 = {1, 1, 4, 1};

    int result = maxEqualHeight(stack1, stack2, stack3);
    cout << "The maximum possible height where all stacks are equal is: " << result << endl;

    return 0;
}
