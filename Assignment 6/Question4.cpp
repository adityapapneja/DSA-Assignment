#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertLast(char val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    bool isPalindrome() {
        Node* start = head;
        Node* end = tail;
        while (start != end && end->next != start) {
            if (start->data != end->data)
                return false;
            start = start->next;
            end = end->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertLast('L');
    dll.insertLast('E');
    dll.insertLast('V');
    dll.insertLast('E');
    dll.insertLast('L');
    if (dll.isPalindrome())
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}
