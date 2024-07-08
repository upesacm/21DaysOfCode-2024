#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    char ch;
    int freq;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

string decodeHuffman(TreeNode* root, const string& binaryString) {
    string decodedText;
    TreeNode* currentNode = root;

    for (char bit : binaryString) {
        if (bit == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            decodedText += currentNode->ch;
            currentNode = root;
        }
    }

    return decodedText;
}

TreeNode* buildSampleHuffmanTree() {
    TreeNode* root = new TreeNode('\0', 5);
    root->left = new TreeNode('A', 3);
    root->right = new TreeNode('\0', 2);
    root->right->left = new TreeNode('B', 1);
    root->right->right = new TreeNode('C', 1);
    return root;
}

int main() {
    TreeNode* huffmanTree = buildSampleHuffmanTree();
    string binaryString = "1001011";

    string decodedText = decodeHuffman(huffmanTree, binaryString);
    cout << "Decoded text: " << decodedText << endl; 

    delete huffmanTree->left;
    delete huffmanTree->right->left;
    delete huffmanTree->right->right;
    delete huffmanTree->right;
    delete huffmanTree;

    return 0;
}
