#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int calculateHeight(const vector<int>& cylinders) {
    int height = 0;
    for (int cylinder : cylinders) {
        height += cylinder;
    }
    return height;
}

int equalizeStackHeights(vector<int>& cylinders1, vector<int>& cylinders2, vector<int>& cylinders3) {
    stack<int> stack1, stack2, stack3;
    for (int i = cylinders1.size() - 1; i >= 0; --i) {
        stack1.push(cylinders1[i]);
    }
    for (int i = cylinders2.size() - 1; i >= 0; --i) {
        stack2.push(cylinders2[i]);
    }
    for (int i = cylinders3.size() - 1; i >= 0; --i) {
        stack3.push(cylinders3[i]);
    }
    
    int height1 = calculateHeight(cylinders1);
    int height2 = calculateHeight(cylinders2);
    int height3 = calculateHeight(cylinders3);
    
    while (!(height1 == height2 && height2 == height3)) {
        if (height1 >= height2 && height1 >= height3) {
            height1 -= stack1.top();
            stack1.pop();
        } else if (height2 >= height1 && height2 >= height3) {
            height2 -= stack2.top();
            stack2.pop();
        } else if (height3 >= height1 && height3 >= height2) {
            height3 -= stack3.top();
            stack3.pop();
        }
    }
    
    return height1;
}

int main() {
    int numCylinders1, numCylinders2, numCylinders3;
    
    cout << "Enter the number of cylinders in stack 1: ";
    cin >> numCylinders1;
    vector<int> cylinders1(numCylinders1);
    cout << "Enter the heights of cylinders in stack 1: ";
    for (int i = 0; i < numCylinders1; ++i) {
        cin >> cylinders1[i];
    }
    
    cout << "Enter the number of cylinders in stack 2: ";
    cin >> numCylinders2;
    vector<int> cylinders2(numCylinders2);
    cout << "Enter the heights of cylinders in stack 2: ";
    for (int i = 0; i < numCylinders2; ++i) {
        cin >> cylinders2[i];
    }
    
    cout << "Enter the number of cylinders in stack 3: ";
    cin >> numCylinders3;
    vector<int> cylinders3(numCylinders3);
    cout << "Enter the heights of cylinders in stack 3: ";
    for (int i = 0; i < numCylinders3; ++i) {
        cin >> cylinders3[i];
    }
    
    cout << endl << equalizeStackHeights(cylinders1, cylinders2, cylinders3) << endl;
}
