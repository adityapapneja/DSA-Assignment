#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printFirstNonRepeating(string str) {

    vector<int> freq(26, 0);
    queue<char> q;
    
    for(char ch : str) {
        freq[ch - 'a']++;
        q.push(ch);
        while (!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();
        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << -1 << " ";
    }
    cout << endl;
}

int main() {

    string input = "aabc";
    printFirstNonRepeating(input);
    
    return 0;
}
