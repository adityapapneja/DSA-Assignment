#include <iostream>
#include <stack>
using namespace std;

string reverseString(string s) {
    stack<char> st;
    for (char c : s) {
        st.push(c);
    }
    
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }
    return reversed;
}

int main() {
    string str;
    getline(cin, str);
    cout << reverseString(str) << endl;
    return 0;
}
