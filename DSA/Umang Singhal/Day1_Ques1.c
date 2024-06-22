#include <stdio.h>

int main() {
    int n; 
    printf("Enter the number of squares in the chocolate bar: ");
    scanf("%d", &n);
    
    int squares[n]; 
    printf("Enter the numbers on the chocolate squares: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &squares[i]);
    }
    
    int d, m; 
    printf("Enter Raju's birth day and birth month: ");
    scanf("%d %d", &d, &m);
    
    int count = 0;
    
    for (int i = 0; i <= n - m; i++) {
        int sum = 0;
        
        for (int j = i; j < i + m; j++) {
            sum += squares[j];
        }
        
        if (sum == d) {
            count++;
        }
    }
    
    printf("Number of ways to divide the bar: %d\n", count);
    
    return 0;
}

