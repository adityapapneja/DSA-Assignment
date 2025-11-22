#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(Node* node, int minVal, int maxVal) {
    if (!node) return true;
    if (node->data <= minVal || node->data >= maxVal)
        return false;
    return isBSTUtil(node->left, minVal, node->data) &&
           isBSTUtil(node->right, node->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "True\n";
    else
        cout << "False\n";

    Node* notBST = new Node(10);
    notBST->left = new Node(5);
    notBST->right = new Node(8); // Violates BST property

    if (isBST(notBST))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
