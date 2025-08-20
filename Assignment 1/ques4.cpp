#include<iostream>
using namespace std;

class Operation{
public:
    void reverseArray(int arr[] , int &size)
    {
        cout << "Before Reversing Array: "<< endl;
        displayArray(arr, size);

        int i = 0;
        int j = size-1;
        while(j > i)
        {
            swap(arr[i] , arr[j]);
            i++;
            j--;
        }

        cout << "After Reversing Array: "<< endl;
        displayArray(arr, size);
    }

    void matrixMultiplication(int arr1[][3], int arr2[][2], int r1, int c1, int r2, int c2){

        if(c1 != r2){
            cout << "Matrix Multiplication Not Possible(col of A != row of B)"<<endl;
            return;
        }

        cout << "Matrix Obtained After Multiplication: "<< endl;
        for(int i = 0; i < r1; i++){
            for(int j = 0; j < c2; j++){
                int sum = 0;
                for(int  k = 0; k < c1; k++){
                    sum += arr1[i][k] * arr2[k][j];
                }
                cout << sum << " ";
            }
            cout << endl;
        }
    }

    void transpose(const int arr[][3], int r, int c) {

        cout << "Transpose of the Matrix:\n";
        for (int i = 0; i < c; i++) {               // columns become rows
            for (int j = 0; j < r; j++) {
                cout << arr[j][i] << " ";
            }
            cout << endl;
        }
    }

    void displayArray(int arr[], int size) {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};



int main()
{
    

    int array[5] = {5, 6, 2, 13, 7};
    int size = 5;

    int arr_1 [3][3] = { {1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9} };

    int arr_2 [3][2] = { {4, 5},
                         {6, 1}, 
                         {1, 7}};

    int choice;
    Operation op;

    while(true){

        cout << "\n---- MENU ----" <<endl;
        cout << "a. Reverse the elements if an array." << endl;
        cout << "b. find the Matrix multiplication." << endl;
        cout << "c. Find the Transpose of a Matrix." << endl;
        cout << "d. Exit\n" << endl;

        cout << "Enter Choice: ";
        cin >> choice;
       
        switch(choice){
            
            case 'a': op.reverseArray(array, size); break;
            case 'b': op.matrixMultiplication(arr_1, arr_2, 3, 3, 3, 2); break;
            case 'c': op.transpose(arr_1, 3, 3); break;
            case 'd': cout << "Exiting Program...." ; return 0;
            default : cout << "Invalid Choice! Try Again." << endl;

        }
    }

    return 0;
}