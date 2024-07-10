#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void decodeString(Node* root, char* binaryString) {
    Node* temp = root;
    int i = 0;
    while (binaryString[i] != '\0') {
        if (binaryString[i] == '0') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        i++;
        if (temp->left == NULL && temp->right == NULL) {
            printf("%c", temp->data);
            temp = root;
        }
    }
}

int main() {
    Node* root = createNode('\0');
    root->left = createNode('A');
    root->right = createNode('\0');
    root->right->left = createNode('C');
    root->right->right = createNode('B');

    char binaryString[] = "1001011";
    printf("Decoded text: ");
    decodeString(root, binaryString);
    printf("\n");

    return 0;
}
