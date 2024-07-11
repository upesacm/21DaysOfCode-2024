#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
const char* hasCycle(int *next, int length) {
    int slow = 0;
    int fast = 0;
    while (fast != -1 && next[fast] != -1) {
        slow = next[slow];
        fast = next[next[fast]];
        if (slow == fast) {
            return "cycle";
        }
    }
    return "no cycle";
}
int main() {
    int next[MAX_NODES];
    int length, i;
    for (i = 0; i < MAX_NODES; i++) {
        next[i] = -1;
    }
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &length);
    if (length > MAX_NODES) {
        printf("Number of nodes exceeds the maximum allowed (%d)\n", MAX_NODES);
        return 1;
    }
    printf("Enter the next node for each node (use -1 for no next node):\n");
    for (i = 0; i < length; i++) {
        printf("Node %d points to: ", i);
        scanf("%d", &next[i]);
    }
    const char* result = hasCycle(next, length);
    printf("The linked list is a %s.\n", result);
    return 0;
}
