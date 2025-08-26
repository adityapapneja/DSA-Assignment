#include<iostream>
using namespace std;

const int MAX_SIZE = 20;

void createArray(int array[],int &size){

    cout << "Enter the size of Array: ";
    cin >> size;

    if(size < 1 || size >= MAX_SIZE){
        cout << "Invalid Size. Setting size to 0"  << endl;
        size = 0;
        return;
    }

    cout<< "Enter the Elements in the Array : " << endl;
    for(int i = 0 ; i < size ; i++){
        cin >> array[i];
    }
}

void displayArray(int arr[] , int &size){

    cout << "Given Array: ";
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int array[] , int &size){

    int ele;
    cout<< "Enter the Element: ";
    cin >> ele;

    int idx;
    cout << "Enter the Index Position: ";
    cin >> idx;

    if(idx < 0 || idx > size){
        cout << "INVALID INDEX!"<<endl;
        return;
    }
    
    for(int j = size; j > idx ; j--){
        array[j] = array[j-1];
    }

    array[idx] = ele;
    size++;
    cout << endl;
    
    cout << "Array After Modification:" << endl; 
    displayArray(array , size);
}

void deleteElement(int array[] , int &size){

    int indx;
    cout << "Enter the Index of Element To delete: ";
    cin >> indx;

    if(indx < 0 || indx >=size){
        cout << "INVALID INDEX!"<<endl;
        return;
    }

    for(int i = indx ; i < size-1 ; i++){
        array[i] = array[i+1];
    }

    cout << endl;
    size--;

    cout << "Array After Modification:" << endl; 
    displayArray(array , size);
}

void linearSearch(int array[] , int &size){
    int ele;
    cout << "Enter the Element to Search: ";
    cin  >> ele;

    int result = -1;
    for (int i = 0 ; i < size ; i++){
        if(ele == array[i]){
            result = i;
            break;
        }
    }
    cout << "The Index of the Element is "<< result << endl;
}

int main(){

    

    int array[MAX_SIZE] = {1,5,4,36,12,44};
    int size = 6;

    while(true){

        cout << "\n---- MENU ----" << endl;
        cout << "1. Create an Array" << endl;
        cout << "2. Display" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Delete " << endl;
        cout << "5. Linear search" << endl;
        cout << "6. Exit" << endl;

        cout << endl;
        cout << "Enter Your choice: ";
        int choice;
        cin >> choice;


        switch(choice){
            case 1: createArray(array, size); break;
            case 2: displayArray(array, size); break;
            case 3: insertElement(array, size); break;
            case 4: deleteElement(array, size); break;
            case 5: linearSearch(array, size); break;
            case 6: cout << "Exiting Program...." << endl; return 0;
            default : cout << "Invalid Choice. Try Again." << endl;
        }
       
    }
}   
    
