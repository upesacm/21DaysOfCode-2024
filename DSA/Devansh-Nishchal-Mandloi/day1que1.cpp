//For this soln, I have used the "Sliding Window" technque. I solved the leetcode's challenge problem this morning it was based on sliding window as well, therefore the approach hit me in no time
//This is an efficient solution with the time complexity of: O(n) {approximately as O(month) + O(n)} and constant space complexity because no space other than that used for input vector is used here!

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int possibleDivisions(vector<int>& chocolates, int day, int month) {
        int n = chocolates.size();
        int ways = 0;

      //the base case
        if (n < month) {
            return 0;
        }

        int windowSum = 0;
        for (int i = 0; i < month; ++i) {
            windowSum += chocolates[i];
        }

        if (windowSum == day) {
            ways++;
        }

        for (int i = month; i < n; ++i) {
            windowSum += chocolates[i];  
            windowSum -= chocolates[i - month]; 
          //in the above two lines, the first line takes the next element in the window and the next line removes the first element out of the window, this is-
          // bascially the concept of Sliding Window as the Window is shifted by one place in the vector 
            if (windowSum == day) {
                ways++;
            }
        }

        return ways;
    }
};

int main() {
    int n;

    cout << "Enter the size of chocolate or the number of chocolate blocks: ";
    cin >> n;

    int month = 0, day = 0;
    cout << "Enter the birth month and day of Raju one by one, in that order: ";
    cin >> month >> day;
   
    vector<int> chocolates(n);
    cout << "Enter the numbers on each block starting from the first block: ";
    for (int i = 0; i < n; ++i) {
        cin >> chocolates[i];
    }

    Solution sol;
    int result = sol.possibleDivisions(chocolates, day, month);

    cout << "The number of possible ways in which the chocolate can be divided is: " << result << endl;

    return 0;
}
