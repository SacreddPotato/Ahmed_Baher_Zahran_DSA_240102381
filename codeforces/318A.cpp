#include <vector>
#include <iostream>

using namespace std;

int kIndex(int num, int pos) {
    vector<int> nums;
    vector<int> evenNums;
    pos--;

    for (int i = 1; i <= num; i++) {
        // cout << i << " ";
        if (i % 2 == 0) {
            evenNums.push_back(i);
        } else {
            nums.push_back(i);
        }
    }
    // cout << "\n\n";
    nums.insert(nums.end(), evenNums.begin(), evenNums.end());
    return nums[pos];
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << kIndex(n, k) << "\n";

    return 0;
}