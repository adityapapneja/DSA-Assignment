#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
    Node* root;
public:
    BST() : root(nullptr) {}

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool searchRecursive(Node* node, int key) {
        if (!node) return false;
        if (node->data == key) return true;
        if (key < node->data)
            return searchRecursive(node->left, key);
        else
            return searchRecursive(node->right, key);
    }

    bool searchRecursive(int key) {
        return searchRecursive(root, key);
    }

    bool searchNonRecursive(int key) {
        Node* curr = root;
        while (curr) {
            if (curr->data == key) return true;
            curr = key < curr->data ? curr->left : curr->right;
        }
        return false;
    }

    int maximum() {
        Node* curr = root;
        while (curr && curr->right)
            curr = curr->right;
        return curr ? curr->data : -1;
    }

    int minimum() {
        Node* curr = root;
        while (curr && curr->left)
            curr = curr->left;
        return curr ? curr->data : -1;
    }

    Node* findNode(int key) {
        Node* curr = root;
        while (curr) {
            if (curr->data == key)
                return curr;
            curr = key < curr->data ? curr->left : curr->right;
        }
        return nullptr;
    }

    Node* inOrderSuccessor(Node* node) {
        if (!node) return nullptr;
        if (node->right) {
            Node* temp = node->right;
            while (temp->left)
                temp = temp->left;
            return temp;
        }
        Node* succ = nullptr;
        Node* curr = root;
        while (curr) {
            if (node->data < curr->data) {
                succ = curr;
                curr = curr->left;
            }
            else if (node->data > curr->data)
                curr = curr->right;
            else break;
        }
        return succ;
    }

    Node* inOrderPredecessor(Node* node) {
        if (!node) return nullptr;
        if (node->left) {
            Node* temp = node->left;
            while (temp->right)
                temp = temp->right;
            return temp;
        }
        Node* pred = nullptr;
        Node* curr = root;
        while (curr) {
            if (node->data > curr->data) {
                pred = curr;
                curr = curr->right;
            }
            else if (node->data < curr->data)
                curr = curr->left;
            else break;
        }
        return pred;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(25);
    tree.insert(35);
    tree.insert(5);
    tree.insert(15);

    cout << "Inorder: ";
    tree.inorder();

    cout << "Search 25 (Recursive): " << (tree.searchRecursive(25) ? "Found" : "Not Found") << endl;
    cout << "Search 40 (Non-Recursive): " << (tree.searchNonRecursive(40) ? "Found" : "Not Found") << endl;

    cout << "Maximum: " << tree.maximum() << endl;
    cout << "Minimum: " << tree.minimum() << endl;

    Node* node = tree.findNode(25);
    Node* succ = tree.inOrderSuccessor(node);
    Node* pred = tree.inOrderPredecessor(node);
    cout << "In-order Successor of 25: " << (succ ? succ->data : -1) << endl;
    cout << "In-order Predecessor of 25: " << (pred ? pred->data : -1) << endl;

    return 0;
}
