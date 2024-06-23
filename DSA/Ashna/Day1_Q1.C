#include<stdio.h>
int countways(int arr[], int n, int d, int m){
 int count = 0;
 for(int i=0;i<=n-m;i++){
 	int sum=0;
 	for(int j=0;j<m;j++){
 		sum+=arr[i+j];
	 }
	 if (sum==d){
	 	count++;
	 }
	 	
  }
  return count;
  
}
int main(){
	int n;
	printf("enter the number of chocolates in the array:  ");
	scanf("%d\n",&n);
	int arr[n];
	printf("enter the elements of array chocolates: ");
	for(int i=0;i<n;i++){
	 scanf("%d\n",&arr[i]);
	 }
	int d,m;
	printf("print raju birthday date: ");
	scanf("%d\n",&d);
	printf("enetr raju birthday month: ");
	scanf("%d\n",&m);
	
	int result = countways(arr,n,d,m);
	printf("The number of ways to divide the bar: %d\n ",result);
	return 0;
}

