#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue {
    vector<int> heap;
public:
    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i-1)/2] < heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        int i = 0, n = heap.size();
        while (true) {
            int largest = i;
            int l = 2*i + 1, r = 2*i + 2;
            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;
            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }
};

class MinPriorityQueue {
    vector<int> heap;
public:
    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i-1)/2] > heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        int i = 0, n = heap.size();
        while (true) {
            int smallest = i;
            int l = 2*i + 1, r = 2*i + 2;
            if (l < n && heap[l] < heap[smallest]) smallest = l;
            if (r < n && heap[r] < heap[smallest]) smallest = r;
            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            } else break;
        }
    }

    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    MaxPriorityQueue maxpq;
    maxpq.push(5);
    maxpq.push(2);
    maxpq.push(9);
    maxpq.push(1);
    cout << maxpq.top() << endl;
    maxpq.pop();
    cout << maxpq.top() << endl;

    MinPriorityQueue minpq;
    minpq.push(5);
    minpq.push(2);
    minpq.push(9);
    minpq.push(1);
    cout << minpq.top() << endl;
    minpq.pop();
    cout << minpq.top() << endl;

    return 0;
}
