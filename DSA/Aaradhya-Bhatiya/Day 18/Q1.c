#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node definition
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue node definition
struct QNode {
    struct Node* node;
    int hd;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

// Queue operations
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct QNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    return temp;
}

void topView(struct Node* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue();
    enqueue(q, root, 0);

    int hd;
    struct Node* node;
    int min_hd = INT_MAX, max_hd = INT_MIN;
    struct Node* topViewMap[1000] = { NULL };

    while (q->front != NULL) {
        struct QNode* qNode = dequeue(q);
        node = qNode->node;
        hd = qNode->hd;
        free(qNode);

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        if (topViewMap[hd + 500] == NULL)
            topViewMap[hd + 500] = node;

        if (node->left != NULL) enqueue(q, node->left, hd - 1);
        if (node->right != NULL) enqueue(q, node->right, hd + 1);
    }

    for (int i = min_hd + 500; i <= max_hd + 500; i++) {
        if (topViewMap[i] != NULL)
            printf("%d ", topViewMap[i]->data);
    }
    printf("\n");
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Top view: ");
    topView(root);

    return 0;
}