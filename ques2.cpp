#include<iostream>
using namespace std;


void removeDuplicateElements(int array[], int &size)
{
    
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {

            if(array[i] == array[j])
            {
                for(int k = j; k < size - 1; k++)
                {
                    array[k] = array[k+1];
                }
                size--;
                j--;
            }

        }
    }

}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main (){

    int arr[] = {4, 5, 9, 4, 9, 6, 5, 4};
    int size = 8;

    cout << "Original array: ";
    displayArray(arr, size);

    removeDuplicateElements(arr, size);

    cout << "Array after removing duplicates: ";
    displayArray(arr, size);


    return 0;
}