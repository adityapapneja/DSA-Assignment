#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }

    void deleteAllOccurrences(int key) {
  
        while (head != nullptr && head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        if (head == nullptr) return;

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == key) {
                Node* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete;
            } else {
                current = current->next;
            }
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << "->";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    SinglyLinkedList sll;
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 1;

    for (int i = 0; i < size; i++) {
        sll.insertAtEnd(arr[i]);
    }

    cout << "Original Linked List: ";
    sll.display();

    int count = sll.countOccurrences(key);
    cout << "Count of " << key << ": " << count << "\n";

    sll.deleteAllOccurrences(key);

    cout << "Updated Linked List after deleting all occurrences of " << key << ": ";
    sll.display();

    return 0;
}
