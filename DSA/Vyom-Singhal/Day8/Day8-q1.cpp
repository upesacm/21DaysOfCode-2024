#include<iostream>
#include<vector>
using namespace std;

int maximumHeightPossible(vector<int>& stk1, vector<int>& stk2, vector<int>& stk3) {
    int height1 = 0, height2 = 0, height3 = 0;
    for(int i = 0; i < stk1.size(); i++) {
        height1 += stk1[i];
    }
    for(int i = 0; i < stk2.size(); i++) {
        height2 += stk2[i];
    }
    for(int i = 0; i < stk3.size(); i++) {
        height3 += stk3[i];
    }
    int i = 0, j = 0, k = 0;
    while(true) {
        if(i == stk1.size() || j == stk2.size() || i == stk3.size()) return 0;
        if(height1 == height2 && height2 == height3) return height1;
        if(height1 > height2 && height1 > height3) {
            height1 -= stk1[i];
            i++;
        } else if(height2 > height1 && height2 > height3) {
            height2 -= stk2[j];
            j++;
        } else {
            height3 -= stk3[k];
            k++;
        }
    }
}

int main() {
    vector<int> stack1 = {3,2,1,1,1};
    vector<int> stack2 = {4,3,2};
    vector<int> stack3 = {1,1,4,1};
    cout << maximumHeightPossible(stack1,stack2,stack3);
}
