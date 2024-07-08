#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a Huffman tree node
struct HuffmanNode {
    char data;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

// Function to create a new Huffman tree node
struct HuffmanNode* newHuffmanNode(char val) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to decode a binary string using the Huffman tree
char* decodeHuffman(struct HuffmanNode* root, const char* binaryString) {
    char* decodedText = (char*)malloc(strlen(binaryString) + 1);
    int decodedIndex = 0;
    struct HuffmanNode* currentNode = root;
    for (int i = 0; binaryString[i] != '\0'; i++) {
        char bit = binaryString[i];
        if (bit == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
        if (currentNode->left == NULL && currentNode->right == NULL) {
            decodedText[decodedIndex++] = currentNode->data;
            currentNode = root;
        }
    }
    decodedText[decodedIndex] = '\0';
    return decodedText;
}

int main() {
    // Create the Huffman tree
    struct HuffmanNode* root = newHuffmanNode('\0');
    root->left = newHuffmanNode('\0');
    root->right = newHuffmanNode('A');
    root->left->left = newHuffmanNode('B');
    root->left->right = newHuffmanNode('C');

    // Decode the binary string
    const char* binaryString = "1001011";
    char* decodedText = decodeHuffman(root, binaryString);
    printf("Decoded text: %s\n", decodedText);

    free(decodedText);
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
