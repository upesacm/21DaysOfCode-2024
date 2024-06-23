#include <stdio.h>
#include <stdlib.h>

int *duplicate(int lead_no, int *leadarr, int *new_len);

int main() {
    int lead_no, no_of_scores, *leadarr, *playerscore_arr, *rank_arr;

    printf("Enter the number of leaderboard entries:\n");
    scanf("%d", &lead_no);

    printf("Enter the number of scores the player got:\n");
    scanf("%d", &no_of_scores);

    leadarr = (int*) malloc(lead_no * sizeof(int));
    playerscore_arr = (int*) malloc(no_of_scores * sizeof(int));
    rank_arr = (int*) malloc(no_of_scores * sizeof(int));

    printf("Enter the scores of the leaderboard:\n");
    for(int i = 0; i < lead_no; i++) {
        scanf("%d", &leadarr[i]);
    }

    printf("Enter the scores of the player:\n");
    for(int i = 0; i < no_of_scores; i++) {
        scanf("%d", &playerscore_arr[i]);
    }

    int new_len;
    int *dup_arr = duplicate(lead_no, leadarr, &new_len);

    for(int i = 0; i < no_of_scores; i++) {
        for(int j = 0; j < new_len; j++) {
            if(playerscore_arr[i] >= dup_arr[j]) {
                rank_arr[i] = j + 1;
                break;
            }
            else{
                rank_arr[i] = j+2; // if the score is less than the lead than the next postion is given to the player
            }
        }
    }

    printf("Here is the rank:\n");
    for(int i = 0; i < no_of_scores; i++) {
        printf("%d\t", rank_arr[i]);
    }

    free(leadarr);
    free(playerscore_arr);
    free(rank_arr);
    free(dup_arr);

    return 0;
}

int *duplicate(int lead_no, int *leadarr, int *new_len) {
    int *duparr = (int*) malloc(lead_no * sizeof(int));
    duparr[0] = leadarr[0];
    int j = 1;

    for(int i = 1; i < lead_no; i++) {
        if(duparr[j - 1] != leadarr[i]) {
            duparr[j] = leadarr[i];
            j++;
        }
    }

    *new_len = j;
    duparr = (int*) realloc(duparr, j * sizeof(int));

    return duparr;
}
