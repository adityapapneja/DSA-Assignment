//	Write a program to find sum of every row and every column in a two-dimensional array.  
#include<iostream>
using namespace std;

void displayMatrix(const int arr[][3], int r, int c){

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
            cout << j;
        }
        cout << endl;
    }
}

void findSum(const int arr[][3], int r, int c){
    
    int rowSum[3] = {0};
    int colSum[3] = {0};

    for(int i = 0; i < r; i++){                    
        for(int j = 0; j < c; j++){        
            rowSum[i] += arr[i][j];
        } 
    }

    for(int j = 0; j < c; j++){                    
        for(int i = 0; i < r; i++){        
            colSum[j] += arr[i][j];
        } 
    }

    // Display results
    cout << "\nRow sums: ";
    for (int i = 0; i < r; i++)
        cout << rowSum[i] << " ";

    cout << "\nColumn sums: ";
    for (int j = 0; j < c; j++)
        cout << colSum[j] << " ";
    cout << endl;
}


int main(){

    int arr[3][3] = { {1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9} };

    cout << "Matrix: " << endl;
    displayMatrix(arr, 3, 3);

    findSum(arr, 3, 3);

    return 0;
}