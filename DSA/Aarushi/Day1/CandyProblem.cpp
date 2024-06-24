// Day1: Question 1
#include<iostream>
#include<vector>
using namespace std;

int WaysToDivideBar(const vector<int>& candy, int day, int month){
    int count = 0;
    int n = candy.size();
    for (int i=0; i<=n-month; i++){
        int segmentSum = 0;
        for (int j=i; j<i+month; j++){
            segmentSum +=candy[j];
    }
    if (segmentSum == day){
        count++;
    }
}
    return count;
}

int main(){
    int n;
    cout <<"Enter the number of candy squares:";
    cin>> n;

    vector <int> candy(n);
    cout<<"Enter the number on the candy squares:";
    for (int i=0; i<n; i++){
        cin>>candy[i];
    }

    int day, month;
    cout<< "Enter birth day:";
    cin>>day;
    cout<< "Enter birth month:";
    cin>>month;

    int result = WaysToDivideBar(candy, day, month);
    cout<<"Number of valid ways to divide the bar:"<< result<< endl;

    return 0;
}

