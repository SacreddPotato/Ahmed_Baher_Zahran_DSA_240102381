#include <vector>

using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sumOfSingleDigits;
        int sumOfDoubleDigits;

        for (int num: nums) {
            if (num >= 10) {
                sumOfDoubleDigits += num;
            } else {
                sumOfSingleDigits += num;
            }
        }

        return (sumOfDoubleDigits > sumOfSingleDigits || sumOfSingleDigits > sumOfDoubleDigits);
    }
};