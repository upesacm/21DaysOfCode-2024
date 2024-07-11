#include <iostream>
#include <vector>
using namespace std;

//This Solution has time complexity of O(n)
string isClassCancelled(int threshold, const vector<int>& arrival_times) {
    int on_time_count = 0;
    for (auto t : arrival_times) {
        if (t <= 0) {
            on_time_count++;
        }
    }
    return on_time_count < threshold ? "YES" : "NO";
}

int main() {
    int threshold = 3;
    vector<int> arrival_times = {-1,-3,5,-4,4,2};
    cout << isClassCancelled(threshold, arrival_times);
    return 0;
}
