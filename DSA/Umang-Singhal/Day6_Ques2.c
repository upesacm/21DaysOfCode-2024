#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
int findMergePoint(int *list1, int length1, int *list2, int length2) {
    int visited[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < length1; i++) {
        visited[list1[i]] = 1;
    }
    for (int i = 0; i < length2; i++) {
        if (visited[list2[i]] == 1) {
            return list2[i];
        }
    }
    return -1;
}
int main() {
    int list1[MAX_NODES], list2[MAX_NODES];
    int length1, length2;
    printf("Enter the number of nodes in the first linked list: ");
    scanf("%d", &length1);
    if (length1 > MAX_NODES) {
        printf("Number of nodes exceeds the maximum allowed (%d)\n", MAX_NODES);
        return 1;
    }
    printf("Enter the nodes of the first linked list:\n");
    for (int i = 0; i < length1; i++) {
        scanf("%d", &list1[i]);
    }
    printf("Enter the number of nodes in the second linked list: ");
    scanf("%d", &length2);
    if (length2 > MAX_NODES) {
        printf("Number of nodes exceeds the maximum allowed (%d)\n", MAX_NODES);
        return 1;
    }
    printf("Enter the nodes of the second linked list:\n");
    for (int i = 0; i < length2; i++) {
        scanf("%d", &list2[i]);
    }
    int mergePoint = findMergePoint(list1, length1, list2, length2);
    if (mergePoint != -1) {
        printf("The merging node value is: %d\n", mergePoint);
    } else {
        printf("There is no merging node.\n");
    }
    return 0;
}
