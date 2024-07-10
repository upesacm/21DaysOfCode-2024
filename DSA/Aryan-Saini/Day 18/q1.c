#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct QueueItem {
    struct Node *node;
    int hd;
    struct QueueItem *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct QueueItem* createQueueItem(struct Node *node, int hd) {
    struct QueueItem *newItem = (struct QueueItem*)malloc(sizeof(struct QueueItem));
    newItem->node = node;
    newItem->hd = hd;
    newItem->next = NULL;
    return newItem;
}

void enqueue(struct QueueItem **front, struct QueueItem **rear, struct Node *node, int hd) {
    struct QueueItem *newItem = createQueueItem(node, hd);
    if (*rear) {
        (*rear)->next = newItem;
    }
    *rear = newItem;
    if (!*front) {
        *front = *rear;
    }
}

struct QueueItem* dequeue(struct QueueItem **front) {
    if (!*front) return NULL;
    struct QueueItem *temp = *front;
    *front = (*front)->next;
    return temp;
}

void findMinMax(struct Node *root, int *min, int *max, int hd) {
    if (!root) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(root->left, min, max, hd - 1);
    findMinMax(root->right, min, max, hd + 1);
}

void printTopView(struct Node *root) {
    if (!root) return;

    struct QueueItem *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root, 0);

    int topView[1000] = {0};
    int visited[1000] = {0};

    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    while (front) {
        struct QueueItem *item = dequeue(&front);
        int hd = item->hd;
        struct Node *node = item->node;

        if (!visited[hd - min]) {
            topView[hd - min] = node->data;
            visited[hd - min] = 1;
        }

        if (node->left) enqueue(&front, &rear, node->left, hd - 1);
        if (node->right) enqueue(&front, &rear, node->right, hd + 1);

        free(item);
    }

    for (int i = 0; i <= max - min; ++i) {
        if (visited[i]) {
            printf("%d ", topView[i]);
        }
    }
    printf("\n");
}

int main() {
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Top view of the binary tree is: ");
    printTopView(root);

    return 0;
}
