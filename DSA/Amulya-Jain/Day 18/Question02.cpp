#include <iostream>
#include <string>

using namespace std;

struct HuffmanNode {
    char data;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

string decodeHuffman(HuffmanNode* root, const string& binaryString) {
    string decodedText = "";
    HuffmanNode* currentNode = root;

    for (char bit : binaryString) {
        if (bit == '0') {
            currentNode = currentNode->left;
        } else if (bit == '1') {
            currentNode = currentNode->right;
        }

        // append the character to the decoded text if a leaf node is reached
        if (!currentNode->left && !currentNode->right) {
            decodedText += currentNode->data;
            currentNode = root;
        }
    }

    return decodedText;
}

int main() {
    HuffmanNode* root = new HuffmanNode('\0');
    root->left = new HuffmanNode('A');
    root->right = new HuffmanNode('\0');
    root->right->left = new HuffmanNode('B');
    root->right->right = new HuffmanNode('C');

    string binaryString = "1001011";
    string decodedText = decodeHuffman(root, binaryString);
    cout << decodedText << endl;

    return 0;
}
