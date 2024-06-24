#include<stdio.h>

int main(){
	int size;
	printf("Enter the no. of blocks in the candy : ");
	scanf("%d",&size);
	int arr[size];
	for(int i = 0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int day_raju,month_raju,count=0,sum,j;
	printf("Enter Raju's birth month : ");
	scanf("%d",&month_raju);
	printf("Enter Raju's birth day : ");
	scanf("%d",&day_raju);
	for(int i = 0;i<size;i++){
		j=0;
		sum=0;
		while(j<month_raju&&i+j<size){
			sum+=arr[i+j];
			j++;
		}
		if(day_raju==sum)
			count++;
	}
	printf("%d",count);
}
