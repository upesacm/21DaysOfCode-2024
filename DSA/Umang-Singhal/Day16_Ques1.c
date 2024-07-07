#include <stdio.h>
#include <stdlib.h>
void postorderTraversal(int nodeIndex, int left[], int right[], int values[]);
void buildTree(int numNodes, int values[], int left[], int right[]);
void postorderTraversal(int nodeIndex, int left[], int right[], int values[]) {
    if (nodeIndex == -1) {
        return;
    }
    postorderTraversal(left[nodeIndex], left, right, values);
    postorderTraversal(right[nodeIndex], left, right, values);
    printf("%d ", values[nodeIndex]);
}
void buildTree(int numNodes, int values[], int left[], int right[]) {
    for (int i = 0; i < numNodes; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &values[i]);
        printf("Enter index of left child of node %d (-1 if no left child): ", i);
        scanf("%d", &left[i]);
        printf("Enter index of right child of node %d (-1 if no right child): ", i);
        scanf("%d", &right[i]);
    }
}
int main() {
    int numNodes;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &numNodes);
    int values[numNodes];
    int left[numNodes];
    int right[numNodes];
    buildTree(numNodes, values, left, right);
    int rootIndex;
    printf("Enter the index of the root node: ");
    scanf("%d", &rootIndex);
    printf("Postorder Traversal: ");
    postorderTraversal(rootIndex, left, right, values);
    printf("\n");
    return 0;
}
