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
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void decode(Node* root, char* binaryString) {
    Node* current = root;
    int length = strlen(binaryString);
    char decodedText[100]; 
    int textIndex = 0;

    for (int i = 0; i < length; i++) {
        if (binaryString[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            decodedText[textIndex++] = current->data;
            current = root;
        }
    }

    decodedText[textIndex] = '\0';
    printf("Decoded Text: %s\n", decodedText);
}

int main() {
    Node* root = createNode('\0');
    Node* A = createNode('A');
    Node* B = createNode('B');
    Node* C = createNode('C');

    root->left = createNode('\0');
    root->right = B;
    root->left->left = A;
    root->left->right = C;

    char binaryString[] = "1001011";
    decode(root, binaryString); 
    return 0;
}
