#include<stdio.h>

int main(){
	int size;
	printf("Enter the no. of elements in array : ");
	scanf("%d",&size);
	int arr[size];
	for(int i = 0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int count=0,k;
	printf("Enter the integer k : ");
	scanf("%d",&k);
	for(int i = 0 ; i <size ;i++){
		for (int j = i+1;j<size;j++){
			if((arr[i]+arr[j])%k==0){
				count++;
			}
		}
	}
	printf("%d",count);
}
