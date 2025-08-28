#include <iostream>
using namespace std;

class Stack {
    int top;
    int size;
    int* arr;

public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << "Pushed: " << x << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;
    Stack s(size);
    int choice, val;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. isEmpty\n6. isFull\n7. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 6:
                cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n");
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
                
        }
    } while (choice != 7);

    return 0;
}
