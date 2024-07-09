#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* getNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

string decode(Node* root, string binaryString) {
    Node* current = root;
    string decodedString = "";

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

int main() {
    Node* root = getNode('\0');
    root->left = getNode('\0');
    root->right = getNode('A');
    root->left->left = getNode('B');
    root->left->right = getNode('C');

    string binaryString = "1001011";
    string decodedString = decode(root, binaryString);

    cout << decodedString << endl;

    return 0;
}
