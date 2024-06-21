#include <stdio.h>
#include <stdlib.h>

int CountWays(int* CandyBar, int n, int BirthMonth, int BirthDay) {
    int count = 0;
    

    for (int start = 0; start <= n - BirthMonth; start++) {
        int sum = 0;
        
        
        for (int i = start; i < start + BirthMonth; i++) {
            sum += CandyBar[i];
        }
        
        if (sum == BirthDay) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int n, BirthMonth, BirthDay;
    
   
    printf("Enter the length of the candy bar: ");
    scanf("%d", &n);
    
   
    int* CandyBar = (int*)malloc(n * sizeof(int));
    printf("Enter the numbers on the candy bar: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &CandyBar[i]);
    }
    
    
    printf("Enter Raju's Birth Month: ");
    scanf("%d", &BirthMonth);
    printf("Enter Raju's Birth Day: ");
    scanf("%d", &BirthDay);
    
  
    int result = CountWays(CandyBar, n, BirthMonth, BirthDay);
    printf("Number of ways to break the candy bar: %d\n", result);
    
    return 0;
}
