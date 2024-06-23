#include<stdio.h>

int main(){
	int size;
	printf("Enter the number of students :");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the time of entery of students : \n");
	for(int i = 0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int min_num,count=0;
	printf("Enter the minimum students required for class : ");
	scanf(" %d",&min_num);
	for(int i = 0 ; i < size;i++){
		if(arr[i]<0){
			count++;
		}
	}
	if(count==min_num){
		printf("NO");
	}
	else
		printf("YES");
}
