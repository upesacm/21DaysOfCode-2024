#include<stdio.h>

int main(){
	int size;
	printf("Enter the number people in leader board :");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the score of leaderboard : \n");
	for(int i = 0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int p_size;
	printf("Enter the number of attempts of player : ");
	scanf("%d",&p_size);
	int arr_p[p_size];
	printf("Enter the score of player in the attempts :\n");
	for(int i = 0;i<p_size;i++){
		scanf("%d",&arr_p[i]);
	}
	int fin[p_size];
	for(int i = 0; i< p_size ; i++){
		for(int j = 0;j<size;j++){
			if(arr_p[i]>arr[j]){
				fin[i]=j+1;
				break;
			}
			else if(arr_p[i]==arr[j]){
				fin[i]=j;
				break;
			}
			else{
				fin[i]=j+1;
			}
		}
	}
	for(int i = 0 ; i <p_size;i++){
		printf("%d\t",fin[i]);
	}
}
