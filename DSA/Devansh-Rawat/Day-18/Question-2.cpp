#include <iostream>
#include <string>
using namespace std;
struct HuffmanNode {
    char data;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char val) : data(val), left(nullptr), right(nullptr) {}
};
string decodeHuffman(HuffmanNode* root, const string& binaryString) {
    string decodedText = "";
    HuffmanNode* currentNode = root;
    for (char bit : binaryString) {
        if (bit == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            decodedText += currentNode->data;
            currentNode = root; 
        }
    }
    return decodedText;
}
int main() {
    HuffmanNode* root = new HuffmanNode('\0');
    root->left = new HuffmanNode('\0');
    root->right = new HuffmanNode('A');
    root->left->left = new HuffmanNode('B');
    root->left->right = new HuffmanNode('C');
    string binaryString = "1001011";
    string decodedText = decodeHuffman(root, binaryString);
    cout << "Decoded text: " << decodedText << endl;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}