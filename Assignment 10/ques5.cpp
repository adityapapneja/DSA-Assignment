#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    unordered_set<Node*> visited;
    Node* curr = head;
    while (curr) {
        if (visited.count(curr))
            return true;
        visited.insert(curr);
        curr = curr->next;
    }
    return false;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // Creates a cycle

    if (hasCycle(n1))
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}
