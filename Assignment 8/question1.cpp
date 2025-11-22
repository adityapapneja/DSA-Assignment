#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void PreOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(Node* root) {
    if (root != nullptr) {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

void PostOrder(Node* root) {
    if (root != nullptr) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(6);
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);
    root->right->right->left = new Node(8);

    cout << "Pre-order Traversal: ";
    PreOrder(root);
    cout << "\nIn-order Traversal: ";
    InOrder(root);
    cout << "\nPost-order Traversal: ";
    PostOrder(root);

    return 0;
}
