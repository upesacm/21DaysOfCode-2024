#include <stdio.h>

int main() {
    int len; //Number of squares in the candy bar
    int candy[25]; //Array to store candy squares (maximum 25)
    int day,month,count = 0;

    //Get candy bar length from user
    printf("Enter the number of squares in the candy bar: ");
    scanf("%d", &len);

    //Checking length
    if (len <= 0 || len > 100) {
        printf("Invalid length. Please enter a value between 1 and 25.\n");
        return 1;
    }

    // Get candy square values from user
    printf("Enter the value of each square:\n");
    for (int i = 0; i < len; i++) {
        scanf("%d", &candy[i]);
    }

    // Get Raju's birth day and month
    printf("Enter Raju's birth day: ");
    scanf("%d", &day);
    printf("Enter Raju's birth month: ");
    scanf("%d", &month);
  
    if (day <= 0 || month <= 0) {
        printf("Invalid day or month. Enter positive values.\n");
        return 1;
    }

    // Loop through each square
    for (int i = 0; i <= len - month; i++) {
        int sum = 0;
        // Calculate the sum of the segment of length 'month'
        for (int j = i; j < i + month; j++) {
            sum += candy[j];
        }
        //Printing the segment and its sum
        printf("Segment from index %d to %d: ", i, i + month - 1);
        for (int j = i; j < i + month; j++) {
            printf("%d ", candy[j]);
        }
        printf("=> Sum: %d\n", sum);

        if (sum == day) {
            count++;
        }
    }

    printf("Number of valid ways to divide the bar: %d\n", count);
    return 0;
}

