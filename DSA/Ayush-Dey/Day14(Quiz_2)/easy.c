// Least Moves
#include <stdio.h>

int main() {
    int n;// no. of stu
    scanf("%d", &n);
    
    int height[n]; //heights
    for (int i = 0; i < n; ++i) {
        scanf("%d", &height[i]);
    }
    
    int moves = 0;
    
    for (int i = 1; i < n; ++i) {
        if (height[i] < height[i - 1]) {
           
            moves++;

            while (i < n && height[i] < height[i - 1]) {
                i++;
            }
        }
    }
    
    printf("%d\n", moves);
    
    return 0;
}
