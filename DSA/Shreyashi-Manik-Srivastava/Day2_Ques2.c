#include <stdio.h>

void merge(int arr1[], int n, int arr2[], int m, int mergedArray[]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        mergedArray[k++] = arr1[i];
    }
    for (int i = 0; i < m; i++) {
        mergedArray[k++] = arr2[i];
    }
}

void sort(int mergedArray[], int k) {
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (mergedArray[i] < mergedArray[j]) {
                int temp = mergedArray[i];
                mergedArray[i] = mergedArray[j];
                mergedArray[j] = temp;
            }
        }
    }
}

void removeDuplicates(int mergedArray[], int k, int uniqueArray[], int* uniqueCount) {
    int j = 0;
    uniqueArray[j++] = mergedArray[k - 1];
    *uniqueCount = 1;
    for (int i = k - 2; i >= 0; i--) {
        if (mergedArray[i]!= mergedArray[i + 1]) {
            uniqueArray[j++] = mergedArray[i];
            (*uniqueCount)++;
        }
    }
}

int main() {
    int n, num;
    printf("Enter size of the leaderboard: ");
    scanf("%d", &n);

    int leaderboard[n];
    printf("Enter leaderboard scores:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &leaderboard[i]);
    }

    printf("Enter no. of players: ");
    scanf("%d", &num);

    int playerScores[num];
    printf("Enter player scores:");
    for (int i = 0; i < num; i++) {
        scanf("%d", &playerScores[i]);
    }

    int mergedArray[n + num];
    merge(leaderboard, n, playerScores, num, mergedArray);
    sort(mergedArray, n + num);

    int uniqueArray[n + num];
    int uniqueCount;
    removeDuplicates(mergedArray, n + num, uniqueArray, &uniqueCount);

    printf("Ranks of the players:");
    for (int i = 0; i < num; i++) {
        int rank = 1;
        for (int j = 0; j < uniqueCount; j++) {
            if (playerScores[i] < uniqueArray[j]) {
                rank = j + 1;
            }
            if (playerScores[i] == uniqueArray[j]) {
                rank = j + 1;
                break;
            }
        }
        printf("%d ", rank);
    }
    printf("\n");
    return 0;
}