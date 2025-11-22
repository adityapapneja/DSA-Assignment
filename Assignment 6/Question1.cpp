#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insertFirst(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

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
        newNode->prev = temp;
    }

    bool insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) return false;
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        return true;
    }

    bool insertBefore(int key, int val) {
        if (!head) return false;
        if (head->data == key) {
            insertFirst(val);
            return true;
        }
        Node* temp = head->next;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) return false;
        Node* newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        return true;
    }

    bool deleteNode(int key) {
        if (!head) return false;
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) return false;
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        return true;
    }

    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CircularDoublyLinkedList {
    Node* head;
public:
    CircularDoublyLinkedList() : head(nullptr) {}

    void insertFirst(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    void insertLast(int val) {
        if (!head) {
            insertFirst(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }

    bool insertAfter(int key, int val) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    bool insertBefore(int key, int val) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == key) {
                if (temp == head) {
                    insertFirst(val);
                    return true;
                }
                Node* newNode = new Node(val);
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    bool deleteNode(int key) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == key) {
                if (temp->next == temp) {
                    delete temp;
                    head = nullptr;
                    return true;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head)
                    head = temp->next;
                delete temp;
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    bool search(int key) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == key) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    void display() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularDoublyLinkedList cdll;
    int choice, val, key, optype;

    while (true) {
        cout << "\nChoose List Type:\n1. Doubly Linked List\n2. Circular Doubly Linked List\n3. Exit\n";
        cin >> optype;
        if (optype == 3) break;

        cout << "Menu:\n1. Insert First\n2. Insert Last\n3. Insert After Node\n4. Insert Before Node\n5. Delete Node\n6. Search Node\n7. Display List\n8. Back to List Type\n";
        cin >> choice;

        if (choice == 8) continue;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at first: ";
                cin >> val;
                if (optype == 1) dll.insertFirst(val);
                else cdll.insertFirst(val);
                break;
            case 2:
                cout << "Enter value to insert at last: ";
                cin >> val;
                if (optype == 1) dll.insertLast(val);
                else cdll.insertLast(val);
                break;
            case 3:
                cout << "Enter key node after which to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                if (optype == 1) {
                    if (!dll.insertAfter(key, val))
                        cout << "Key not found\n";
                } else {
                    if (!cdll.insertAfter(key, val))
                        cout << "Key not found\n";
                }
                break;
            case 4:
                cout << "Enter key node before which to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                if (optype == 1) {
                    if (!dll.insertBefore(key, val))
                        cout << "Key not found\n";
                } else {
                    if (!cdll.insertBefore(key, val))
                        cout << "Key not found\n";
                }
                break;
            case 5:
                cout << "Enter node value to delete: ";
                cin >> key;
                if (optype == 1) {
                    if (!dll.deleteNode(key))
                        cout << "Node not found\n";
                } else {
                    if (!cdll.deleteNode(key))
                        cout << "Node not found\n";
                }
                break;
            case 6:
                cout << "Enter node value to search: ";
                cin >> key;
                if (optype == 1) {
                    if (dll.search(key))
                        cout << "Node found\n";
                    else cout << "Node not found\n";
                } else {
                    if (cdll.search(key))
                        cout << "Node found\n";
                    else cout << "Node not found\n";
                }
                break;
            case 7:
                if (optype == 1) dll.display();
                else cdll.display();
                break;
            default:
                cout << "Invalid option\n";
        }
    }
    return 0;
}
