#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int minIdx = left, maxIdx = left;
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIdx])
                minIdx = i;
            if (arr[i] > arr[maxIdx])
                maxIdx = i;
        }
        swap(arr[left], arr[minIdx]);
        if (maxIdx == left)
            maxIdx = minIdx;
        swap(arr[right], arr[maxIdx]);
        left++;
        right--;
    }
}

void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[] = {9, 5, 3, 1, 2, 8, 4, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    improvedSelectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
