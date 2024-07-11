#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a Huffman tree node
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new Huffman tree node
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

// Function to decode the binary string using the Huffman tree
void decode(Node* root, char* binaryString) {
    Node* current = root;
    int i = 0;
    while (binaryString[i] != '\0') {
        if (binaryString[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        i++;

        // If a leaf node is reached, print the character and move back to the root
        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data);
            current = root;
        }
    }
    printf("\n");
}

// Driver code
int main() {
    // Create the Huffman tree
    Node* root = createNode('\0');
    root->left = createNode('A');
    root->right = createNode('\0');
    root->right->left = createNode('B');
    root->right->right = createNode('\0');
    root->right->right->left = createNode('C');
    root->right->right->right = createNode('D');

    // Decode the binary string
    char binaryString[] = "01101001";
    decode(root, binaryString);

    return 0;
}