#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int nums[] = {2, 3, 2, 4, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++)
        freq[nums[i]]++;
    for(auto &p : freq)
        cout << p.first << " -> " << p.second << " times\n";
    return 0;
}
