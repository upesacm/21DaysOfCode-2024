#include <iostream>
#include <string>
using namespace std;

struct HuffmanNode {
    char data;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char data) : data(data), left(nullptr), right(nullptr) {}
};

string decodeHuffmanTree(HuffmanNode* root, const string& binaryString) {
    string decodedString;
    HuffmanNode* current = root;

    for (char bit : binaryString) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == nullptr && current->right == nullptr) {
            decodedString += current->data;
            current = root;
        }
    }

    return decodedString;
}

HuffmanNode* buildSampleHuffmanTree() {
    HuffmanNode* root = new HuffmanNode('\0');
    root->right = new HuffmanNode('A');
    root->left = new HuffmanNode('\0');
    root->left->left = new HuffmanNode('B');
    root->left->right = new HuffmanNode('C');
    return root;
}

int main() {
    HuffmanNode* root = buildSampleHuffmanTree();
    string binaryString = "1001011";
    string decodedText = decodeHuffmanTree(root, binaryString);
    cout << "Decoded Text: " << decodedText << endl;
    return 0;
}
