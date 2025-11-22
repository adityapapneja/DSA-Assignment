#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nums[] = {4, 5, 1, 2, 0, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    vector<int> elements, counts(n, 0);
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < elements.size(); j++) {
            if (elements[j] == nums[i]) {
                counts[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            elements.push_back(nums[i]);
            counts[elements.size() - 1] = 1;
        }
    }
    for (int i = 0, idx = 0; i < n; i++, idx = 0) {
        for (; idx < elements.size(); idx++) {
            if (elements[idx] == nums[i] && counts[idx] == 1) {
                cout << nums[i] << endl;
                return 0;
            }
        }
    }
    cout << "No non-repeating element\n";
    return 0;
}
