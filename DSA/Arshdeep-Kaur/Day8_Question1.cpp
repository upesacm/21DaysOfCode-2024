#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int calculateHeight(const vector<int>& stack) {
    int height = 0;
    for (int cylinder : stack) {
        height += cylinder;
    }
    return height;
}

int equalizeStackHeights(vector<int>& stack1, vector<int>& stack2, vector<int>& stack3) {
    stack<int> s1, s2, s3;
    for (int i=stack1.size()-1; i>=0; --i) {
        s1.push(stack1[i]);
    }
    for (int i=stack2.size()-1; i>=0; --i) {
        s2.push(stack2[i]);
    }
    for (int i=stack3.size()-1; i>=0; --i) {
        s3.push(stack3[i]);
    }
    
    int h1 = calculateHeight(stack1);
    int h2 = calculateHeight(stack2);
    int h3 = calculateHeight(stack3);
    
    while (!(h1 == h2 && h2 == h3)) {
        if (h1 >= h2 && h1 >= h3) {
            h1 -= s1.top();
            s1.pop();
        } else if (h2 >= h1 && h2 >= h3) {
            h2 -= s2.top();
            s2.pop();
        } else if (h3 >= h1 && h3 >= h2) {
            h3 -= s3.top();
            s3.pop();
        }
    }
    
    return h1; // or h2 or h3 as they are equal
}

int main() {
    int n1, n2, n3;
    
    cout << "Enter the number of cylinders in stack 1: ";
    cin >> n1;
    vector<int> stack1(n1);
    cout << "Enter the heights of cylinders in stack 1: ";
    for (int i=0; i<n1; ++i) {
        cin >> stack1[i];
    }
    
    cout << "Enter the number of cylinders in stack 2: ";
    cin >> n2;
    vector<int> stack2(n2);
    cout << "Enter the heights of cylinders in stack 2: ";
    for (int i=0; i<n2; ++i) {
        cin >> stack2[i];
    }
    
    cout << "Enter the number of cylinders in stack 3: ";
    cin >> n3;
    vector<int> stack3(n3);
    cout << "Enter the heights of cylinders in stack 3: ";
    for (int i=0; i<n3; ++i) {
        cin >> stack3[i];
    }
    
    cout << endl << equalizeStackHeights(stack1, stack2, stack3) << endl;
}
