#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int leftChild[MAX_SIZE];
int rightChild[MAX_SIZE];
char values[MAX_SIZE];

void insertNode(int root, char value, char* code) {
    int current = root;
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '0') {
            if (leftChild[current] == -1) {
                for (int j = 0; j < MAX_SIZE; j++) {
                    if (values[j] == '\0') {
                        leftChild[current] = j;
                        break;
                    }
                }
            }
            current = leftChild[current];
        } else if (code[i] == '1') {
            if (rightChild[current] == -1) {
                for (int j = 0; j < MAX_SIZE; j++) {
                    if (values[j] == '\0') {
                        rightChild[current] = j;
                        break;
                    }
                }
            }
            current = rightChild[current];
        }
    }
    values[current] = value;
}

void decodeHuffman(int root, const char* binaryString) {
    int current = root;
    for (int i = 0; binaryString[i] != '\0'; i++) {
        if (binaryString[i] == '0') {
            current = leftChild[current];
        } else if (binaryString[i] == '1') {
            current = rightChild[current];
        }

        if (leftChild[current] == -1 && rightChild[current] == -1) {
            printf("%c", values[current]);
            current = root;
        }
    }
    printf("\n");
}

int main() {
    int n, rootValueIndex = 0;
    char value, code[100], binaryString[100];
    
    // Initializing the tree arrays
    for (int i = 0; i < MAX_SIZE; i++) {
        leftChild[i] = -1;
        rightChild[i] = -1;
        values[i] = '\0';
    }

    printf("Enter the number of nodes (leaves) in the Huffman tree: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The Huffman tree is empty\n");
        return 0;
    }

    printf("Enter the value and corresponding binary code for each leaf node:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %s", &value, code);
        insertNode(rootValueIndex, value, code);
    }

    printf("Enter the binary string to be decoded: ");
    scanf("%s", binaryString);

    printf("Decoded text: ");
    decodeHuffman(rootValueIndex, binaryString);

    return 0;
}
