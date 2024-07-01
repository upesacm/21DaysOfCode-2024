/* Question 1: Rohan and Raju have a candy where each square has a number. Rohan wants to
find out how many ways she can break the bar into a contiguous segment such that:
1. The segment length matches Raju's birth month.
2. The sum of the numbers in the segment equals Raju's birth day.
Inputs:
• An array of integers representing the chocolate squares.
• Two integers representing Raju's birth day and birth month.
Output:
• The number of valid ways to divide the bar.
Example:
Candy = [2, 2, 1, 3, 2]
day = 4
month = 2
# Output: 2 
*/

#include<stdio.h>
int count_valid_segments(int candy[], int n, int day, int month){
    int dp[n + 1][day + 1];

    for (int i = 0; i<=n;i++){
        dp[i][0] = 1;
    }

    for(int j = 1; j <= day; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= day; j++){
            if(candy[i - 1] > j){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j] + (dp[i - 1][j - candy[i - 1]] ? dp[i - 1][j - candy[i - 1]] : 0);
            }
        }
    }
    return dp[n][day];
}

int main(){
    int candy[] = {2,2,1,3,2};
    int n = sizeof(candy) / sizeof(candy[0]);
    int day,month;
    printf("Enter the date: ");
    scanf("%d", &day);
    printf("Enter month: ");
    scanf("%d", &month);

    int result = count_valid_segments(candy, n, day, month);
    printf("Number of valid ways to divide the candy bar: %d\n", result);

    return 0;
}