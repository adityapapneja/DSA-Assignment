#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool checkDuplicates(Node* node, unordered_set<int>& seen) {
    if (!node) return false;
    if (seen.count(node->data))
        return true;
    seen.insert(node->data);
    return checkDuplicates(node->left, seen) || checkDuplicates(node->right, seen);
}

int main() {
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(9);
    root->left->left = new Node(2);
    root->left->right = new Node(3); // duplicate value '3'

    unordered_set<int> seen;
    if (checkDuplicates(root, seen))
        cout << "Duplicates Found\n";
    else
        cout << "No Duplicates\n";
    return 0;
}
