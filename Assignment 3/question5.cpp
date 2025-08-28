#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string expr) {

    stack<int> s;
    for (char c : expr) {
        if (isdigit(c)) s.push(c - '0');

        else {
            int val1 = s.top(); s.pop();
            int val2 = s.top(); s.pop();

            switch (c) {
                case '+': s.push(val2 + val1); break;
                case '-': s.push(val2 - val1); break;
                case '*': s.push(val2 * val1); break;
                case '/': s.push(val2 / val1); break;
                case '^': {
                    int res = 1;
                    for(int i=0; i<val1; i++) res *= val2;
                    s.push(res);
                    break;
                }
            }
        }
    }
    return s.top();
}

int main() {

    string postfix;
    getline(cin, postfix);
    cout << evaluatePostfix(postfix) << endl;
    
    return 0;

}
