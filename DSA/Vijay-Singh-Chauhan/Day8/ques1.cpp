#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int maxheight(vector<int>& stack1,vector<int>& stack2,vector<int>& stack3){
    int sum1=accumulate(stack1.begin(),stack1.end(),0);
    int sum2=accumulate(stack2.begin(),stack2.end(),0);
    int sum3=accumulate(stack3.begin(),stack3.end(),0);

    int i=0,j=0,k=0;
    while(true){
        if(i==stack1.size() || j==stack2.size() || k==stack3.size()){
            return 0;
        }
        if(sum1==sum2 && sum2==sum3){
            return sum1;
        }

        if(sum1>=sum2 && sum1>=sum3){
            sum1=sum1-stack1[i];
            i++;
        }
        else if(sum2>=sum1 && sum2>=sum3){
            sum2=sum2-stack2[j];
            j++;
        }
        else if(sum3>=sum1 && sum3>=sum2){
            sum3=sum3-stack3[k];
            k++;
        }
    }
}

int main(){
    vector<int>stack1,stack2,stack3;
    int n1,n2,n3,height;

    cout<<"Enter number of cylinder in Stack1: ";
    cin>>n1;
    for(int i=0;i<n1;i++){
        cin>>height;
        stack1.push_back(height);
    }

    cout<<"Enter number of cylinder in Stack2 ";
    cin>>n2;
    for(int i=0;i<n2;i++){
        cin>>height;
        stack2.push_back(height);
    }

    cout<<"Enter number of cylinder in Stack3: ";
    cin>>n3;
    for(int i=0;i<n3;i++){
        cin>>height;
        stack3.push_back(height);
    }

    int result=maxheight(stack1,stack2,stack3);
    cout<<"Output: ",result;

}
