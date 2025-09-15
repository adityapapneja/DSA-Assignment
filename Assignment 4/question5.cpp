#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty())
            return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackTwoQueues st2q;
    StackOneQueue st1q;
    int choice, impl, val;

    cout << "Choose stack implementation:\n";
    cout << "1. Stack using Two Queues\n";
    cout << "2. Stack using One Queue\n";
    cout << "Enter your choice: ";
    cin >> impl;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Check if Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                if (impl == 1)
                    st2q.push(val);
                else
                    st1q.push(val);
                break;
            case 2:
                if (impl == 1)
                    st2q.pop();
                else
                    st1q.pop();
                break;
            case 3:
                if (impl == 1)
                    cout << "Top element: " << st2q.top() << endl;
                else
                    cout << "Top element: " << st1q.top() << endl;
                break;
            case 4:
                if (impl == 1)
                    cout << (st2q.empty() ? "Stack is empty\n" : "Stack is not empty\n");
                else
                    cout << (st1q.empty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}
