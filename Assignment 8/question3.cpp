#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
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

    Node* deleteNode(Node* node, int key) {
        if (!node) return nullptr;
        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* succ = node->right;
            while (succ->left) succ = succ->left;
            node->data = succ->data;
            node->right = deleteNode(node->right, succ->data);
        }
        return node;
    }

    void deleteElement(int key) {
        root = deleteNode(root, key);
    }

    int maxDepth(Node* node) {
        if (!node) return 0;
        int l = maxDepth(node->left);
        int r = maxDepth(node->right);
        return 1 + (l > r ? l : r);
    }

    int minDepth(Node* node) {
        if (!node) return 0;
        if (!node->left && !node->right)
            return 1;
        if (!node->left)
            return 1 + minDepth(node->right);
        if (!node->right)
            return 1 + minDepth(node->left);
        int l = minDepth(node->left);
        int r = minDepth(node->right);
        return 1 + (l < r ? l : r);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    int getMaxDepth() {
        return maxDepth(root);
    }

    int getMinDepth() {
        return minDepth(root);
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.display();

    tree.deleteElement(30);
    tree.display();

    cout << "Max Depth: " << tree.getMaxDepth() << endl;
    cout << "Min Depth: " << tree.getMinDepth() << endl;

    return 0;
}
