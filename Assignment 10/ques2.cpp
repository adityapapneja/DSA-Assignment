#include <iostream>
#include <unordered_set>
using namespace std;

void printCommon(int A[], int n, int B[], int m) {
    unordered_set<int> setA, result;
    for(int i = 0; i < n; i++)
        setA.insert(A[i]);
    for(int j = 0; j < m; j++)
        if(setA.count(B[j]))
            result.insert(B[j]);
    for(auto x : result)
        cout << x << " ";
    cout << endl;
}

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    printCommon(A, n, B, m);
    return 0;
}
