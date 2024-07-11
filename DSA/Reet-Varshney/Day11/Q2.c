#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int count;
    int max_size;
} min_heap;

min_heap* create_min_heap(int max_size) {
    min_heap* mh = (min_heap*)malloc(sizeof(min_heap));
    mh->heap = (int*)malloc(sizeof(int) * max_size);
    mh->count = 0;
    mh->max_size = max_size;
    return mh;
}

void add_element(min_heap* mh, int value) {
    if (mh->count == mh->max_size) {
        printf("Min heap is full\n");
        return;
    }
    int i = mh->count++;
    mh->heap[i] = value;
    while (i > 0 && mh->heap[i] < mh->heap[(i - 1) / 2]) {
        int parent = (i - 1) / 2;
        int temp = mh->heap[parent];
        mh->heap[parent] = mh->heap[i];
        mh->heap[i] = temp;
        i = parent;
    }
}

int remove_min(min_heap* mh) {
    if (mh->count == 0) {
        printf("Min heap is empty\n");
        return -1;
    }
    int min_val = mh->heap[0];
    mh->heap[0] = mh->heap[--mh->count];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < mh->count && mh->heap[left] < mh->heap[smallest]) smallest = left;
        if (right < mh->count && mh->heap[right] < mh->heap[smallest]) smallest = right;
        if (smallest == i) break;
        int temp = mh->heap[smallest];
        mh->heap[smallest] = mh->heap[i];
        mh->heap[i] = temp;
        i = smallest;
    }
    return min_val;
}

int main() {
    min_heap* mh = create_min_heap(10);
    add_element(mh, 4);
    add_element(mh, 2);
    printf("%d\n", remove_min(mh)); // Output: 2
    printf("%d\n", remove_min(mh)); // Output: 4
    free(mh->heap);
    free(mh);
    return 0;
}
