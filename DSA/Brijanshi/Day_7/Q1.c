#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, p;
    scanf("%d", &n);
    int station[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &station[i]);
    }
    scanf("%d", &p);

    qsort(station, n, sizeof(int), compare);

    long long res = 1e18;
    int left = 0, right = 1e9;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        int prev = -1e9;
        for (int i = 0; i < n; i++) {
            if (station[i] > prev) {
                cnt += (station[i] - prev) / (mid + 1);
                prev = station[i];
            }
        }
        cnt += (station[n-1] - prev) / (mid + 1);
        if (cnt >= p) {
            res = fmin(res, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%lld\n", res);

    return 0;
}
