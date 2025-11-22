#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insertLast(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void makeCircular() {
        if (!head) return;
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if (!head) return false;
        Node* temp = head->next;
        while (temp && temp != head)
            temp = temp->next;
        return temp == head;
    }
};

int main() {
    LinkedList ll;
    ll.insertLast(2);
    ll.insertLast(4);
    ll.insertLast(6);
    ll.insertLast(7);
    ll.insertLast(5);
    ll.makeCircular();
    if (ll.isCircular())
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}
