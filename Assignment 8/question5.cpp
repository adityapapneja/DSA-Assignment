#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool inc) {
    int largestOrSmallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (inc) {
        if (l < n && arr[l] > arr[largestOrSmallest])
            largestOrSmallest = l;
        if (r < n && arr[r] > arr[largestOrSmallest])
            largestOrSmallest = r;
    } else {
        if (l < n && arr[l] < arr[largestOrSmallest])
            largestOrSmallest = l;
        if (r < n && arr[r] < arr[largestOrSmallest])
            largestOrSmallest = r;
    }

    if (largestOrSmallest != i) {
        swap(arr[i], arr[largestOrSmallest]);
        heapify(arr, n, largestOrSmallest, inc);
    }
}

void heapSort(int arr[], int n, bool inc) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, inc);

    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, inc);
    }
}

void printArray(int arr[], int n) {
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {6,2,8,4,1,9,3,5};
    int arr2[] = {6,2,8,4,1,9,3,5};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    heapSort(arr1, n, true);
    printArray(arr1, n);

    heapSort(arr2, n, false);
    printArray(arr2, n);

    return 0;
}
