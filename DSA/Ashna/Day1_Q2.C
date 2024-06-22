#include<stdio.h>
int countpairs(int n, int arr[],int k){
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if ((arr[i]+ arr[j])% k==0){
				count++;
	return count;
			}
		}
	}
}
int main(){
	int n;
	printf("enter the number of elements in the array: ");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements of array: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int k;
	printf("enter the value of k: ");
	scanf("%d",&k);
	int result = countpairs( n,  arr, k);
	printf("The number of valid(i,j) pairs:%d ",result);
	return 0;
}
