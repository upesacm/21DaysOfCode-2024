#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


long long minCostToBuyProperties(int n, int* station, int p) {
   
    qsort(station, n, sizeof(int), cmpfunc);

   
    long long MAX_COST = 2 * (long long)(1e8 + 8);

    
    long long low = 0, high = MAX_COST, result = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

       
        int count = 0;
        int last_position = INT_MIN;

        for (int i = 0; i < n; ++i) {
            if (station[i] - last_position >= mid) {
                last_position = station[i];
                count++;
                if (count == p)
                    break;
            }
        }

        if (count >= p) {
            
            result = mid;
            high = mid - 1;
        } else {
            
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, p;
    scanf("%d", &n);
    int station[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &station[i]);
    }
    scanf("%d", &p);

    long long result = minCostToBuyProperties(n, station, p);
    printf("%lld\n", result);

    return 0;
}
