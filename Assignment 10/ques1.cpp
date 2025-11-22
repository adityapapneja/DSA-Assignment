#include <iostream>
#include <unordered_set>
using namespace std;

bool containsDuplicate(int nums[], int n) {
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (seen.count(nums[i]))
            return true;
        seen.insert(nums[i]);
    }
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    if (containsDuplicate(nums, n))
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}
