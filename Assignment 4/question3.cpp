#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even.\n";
        return;
    }
    queue<int> first, second;
    for(int i = 0; i < n/2; i++) {
        first.push(q.front());
        q.pop();
    }
    while(!q.empty()) {
        second.push(q.front());
        q.pop();
    }
    while(!first.empty() && !second.empty()) {
        q.push(first.front());
        first.pop();
        q.push(second.front());
        second.pop();
    }
}

int main() {
    queue<int> q;
    
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr);
    for(int i = 0; i < n; i++)
        q.push(arr[i]);

    interleaveQueue(q);

    cout << "Interleaved Output: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
