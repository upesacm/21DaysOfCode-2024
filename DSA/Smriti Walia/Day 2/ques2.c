#include<stdio.h>
int main() {
    int l,i,j,num_score;
    
    printf("Enter the number of scores of leader board and player: ");
    scanf("%d",&num_score);
    int ldrboard[num_score],playscore[num_score];

    printf("Enter leaderboard scores: \n");
    for(i=0;i<num_score;i++) {
        scanf("%d",&ldrboard[i]);
    }
    
    printf("Enter the player's scores: \n");
    for(i=0;i<num_score;i++) {
        scanf("%d",&playscore[i]);
    }

    for (i = 0; i < num_score - 1; i++) {
        for (j = 0; j < num_score - i - 1; j++) {
            if (ldrboard[j] < ldrboard[j + 1]) {
                int temp = ldrboard[j];
                ldrboard[j] = ldrboard[j + 1];
                ldrboard[j + 1] = temp;
            }
        }
    }

    printf("Player's ranks after each score: ");
    for (int i = 0; i < num_score; i++) {
        int rank = 1;  
        for (int j = 0; j < num_score; j++) {
            if (playscore[i] >= ldrboard[j]) {
                break;  
      }
      rank++;  
    }
    printf("%d ", rank);
  }
  printf("\n");

  return 0;
}
    
