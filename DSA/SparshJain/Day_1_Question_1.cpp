#include<iostream>
using namespace std;
int Possibilities(int arr[],int size, int Birth_Date , int Birth_Month ){
   
    

int ways=0;    
    for(int i=0;i<=size-Birth_Month;i++){
        int sum=0;
        
        for(int j=i;j<i+Birth_Month;j++){
        
            sum+=arr[j];
            }
        
        if(sum==Birth_Date){
            ways++;
        }
    }
    return ways;

}
int main(){
    int chocoBar[5]={2, 2, 1, 3, 2};
    int Birth_Date;
    int Birth_Month;
    cout<<"Enter the Birth date : \n";
    cin>>Birth_Date;
    cout<<"Enter the Birth month : \n";
    cin>>Birth_Month;
    int count=Possibilities(chocoBar,5,Birth_Date,Birth_Month);
    cout<<count;

}