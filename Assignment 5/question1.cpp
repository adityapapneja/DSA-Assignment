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

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

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

    bool insertBeforeAfter(int target, int val, bool before) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return false;
        }
        Node* newNode = new Node(val);

        if (before) {
           
            if (head->data == target) {
                newNode->next = head;
                head = newNode;
                return true;
            }
            Node* prev = nullptr;
            Node* curr = head;
            while (curr != nullptr && curr->data != target) {
                prev = curr;
                curr = curr->next;
            }
            if (curr == nullptr) {
                cout << "Node with value " << target << " not found.\n";
                delete newNode;
                return false;
            }
            prev->next = newNode;
            newNode->next = curr;
            return true;
        } 
        
        else {
           
            Node* curr = head;
            while (curr != nullptr && curr->data != target) {
                curr = curr->next;
            }
            if (curr == nullptr) {
                cout << "Node with value " << target << " not found.\n";
                delete newNode;
                return false;
            }
            newNode->next = curr->next;
            curr->next = newNode;
            return true;
        }
    }

   
    bool deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return false;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    
    bool deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return false;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return true;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        delete curr;
        return true;
    }


    bool deleteNode(int key) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return false;
        }
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Node with value " << key << " not found.\n";
            return false;
        }
        prev->next = curr->next;
        delete curr;
        return true;
    }

    int searchNode(int key) {
        Node* curr = head;
        int position = 1;
        while (curr != nullptr) {
            if (curr->data == key) {
                return position;
            }
            curr = curr->next;
            position++;
        }
        return -1;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* curr = head;
        cout << "List nodes: ";
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
};

int main() {
    SinglyLinkedList sll;
    int choice, val, target;
    bool before;

    while (true) {
        cout << "\nChoose operation:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search a node\n";
        cout << "9. Display all nodes\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                sll.insertAtBeginning(val);
                cout << "Inserted " << val << " at beginning.\n";
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                sll.insertAtEnd(val);
                cout << "Inserted " << val << " at end.\n";
                break;

            case 3:
                cout << "Enter target node value to insert before: ";
                cin >> target;
                cout << "Enter value to insert before " << target << ": ";
                cin >> val;
                before = true;
                if (sll.insertBeforeAfter(target, val, before)) {
                    cout << "Inserted " << val << " before " << target << ".\n";
                }
                break;

            case 4:
                cout << "Enter target node value to insert after: ";
                cin >> target;
                cout << "Enter value to insert after " << target << ": ";
                cin >> val;
                before = false;
                if (sll.insertBeforeAfter(target, val, before)) {
                    cout << "Inserted " << val << " after " << target << ".\n";
                }
                break;

            case 5:
                if (sll.deleteFromBeginning()) {
                    cout << "Deleted node from beginning.\n";
                }
                break;

            case 6:
                if (sll.deleteFromEnd()) {
                    cout << "Deleted node from end.\n";
                }
                break;

            case 7:
                cout << "Enter value of node to delete: ";
                cin >> val;
                if (sll.deleteNode(val)) {
                    cout << "Deleted node with value " << val << ".\n";
                }
                break;

            case 8:
                cout << "Enter value of node to search: ";
                cin >> val;
                int pos;
                pos = sll.searchNode(val);
                if (pos != -1) {
                    cout << "Node with value " << val << " found at position " << pos << ".\n";
                } else {
                    cout << "Node with value " << val << " not found.\n";
                }
                break;

            case 9:
                sll.display();
                break;

            case 10:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}
