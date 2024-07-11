#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int min_cost_to_buy_properties(int n, int station[], int p) {
    qsort(station, n, sizeof(int), compare);
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        int left = i, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid - i + 1 >= p) {
                int max_diff = fmax(abs(station[mid] - station[i]), abs(station[mid + p - 1 - i] - station[mid]));
                res = fmin(res, max_diff);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int station[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &station[i]);
    }
    int p;
    scanf("%d", &p);
    printf("%d\n", min_cost_to_buy_properties(n, station, p));
    return 0;
}
