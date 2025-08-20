#include<iostream>
#include<string>
using namespace std;

void concatenateStrings(){

    string s1, s2;
    cout<<"Enter first string:";
    getline(cin, s1);
    cout<<"Enter second string:";
    getline(cin, s2);

    string concatenated = s1 + s2;
    cout << "Concatenated string: " << concatenated << endl;

}

void reverseString(){

    string str;
    cout<<"Enter a string: ";
    getline(cin, str);

    for(int i=0, j=str.size()-1 ; i<j ; i++,j--){
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
    cout << "Reversed string: " << str << endl;
}

void removeVowels(){

    string s1, r;
    cout << "Enter a string: ";
    getline(cin, s1);

    for(int i = 0; i < s1.size(); i++){
        char c = s1[i];
        if(c >= 'A' && c <= 'Z') c = c + 32; 
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
            r += s1[i];
    }
    cout << "String After removing vowels: " <<  r << endl;
}

void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    string a[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, a[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                string t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

void upperToLower(){

    char c;
    cout << "Enter an uppercase character: ";
    cin >> c;
    if(c >= 'A' && c <= 'Z')
        c = c + 32; 
    cout << "Lowercase: " << c << endl;
}

int main(){

    int ch;
    do{
        cout << "\nMenu:\n";
        cout << "1. Concatenate\n";
        cout << "2. Reverse\n";
        cout << "3. Remove Vowels\n";
        cout << "4. Sort Strings\n";
        cout << "5. Upper to Lower\n";
        cout << "0. Exit\n" << endl;
        cout << "Enter choice: ";

        cin>>ch;
        cin.ignore();

        switch(ch){
            case 1 : concatenateStrings(); break;
            case 2 : reverseString(); break;
            case 3 : removeVowels(); break;
            case 4 : sortStrings(); break;
            case 5 : upperToLower(); break;
            case 0 : cout<<"Exiting...\n"; break;
            default : cout<<"Invalid choice\n";
        }
    }while(ch!=0);

    return 0;
}