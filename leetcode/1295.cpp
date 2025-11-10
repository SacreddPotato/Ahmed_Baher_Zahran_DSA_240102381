#include <vector>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int numOfDigits;
        int ans = 0;

        for (int num: nums) {
            numOfDigits = 0;
            do {
                num /= 10;
                numOfDigits += 1;
            } while (num > 0);

            if (numOfDigits % 2 == 0) {
                ans += 1;
            }
        }

        return ans;
    }
};