#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman tree node definition
struct HNode {
    char data;
    struct HNode *left, *right;
};

struct HNode* newHNode(char data) {
    struct HNode* node = (struct HNode*)malloc(sizeof(struct HNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void decodeHuff(struct HNode* root, char* binStr) {
    struct HNode* cur = root;
    for (int i = 0; i < strlen(binStr); i++) {
        if (binStr[i] == '0') cur = cur->left;
        else cur = cur->right;

        if (cur->left == NULL && cur->right == NULL) {
            printf("%c", cur->data);
            cur = root;
        }
    }
    printf("\n");
}

int main() {
    struct HNode* root = newHNode('\0');
    root->left = newHNode('A');
    root->right = newHNode('\0');
    root->right->left = newHNode('B');
    root->right->right = newHNode('C');

    char binStr[] = "1001011";
    printf("Decoded text: ");
    decodeHuff(root, binStr);

    return 0;
}
