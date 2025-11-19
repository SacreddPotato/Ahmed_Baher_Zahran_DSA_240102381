#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int count = 0;

        for (int num: nums) {
            if (num == 1) {
                count++;
            } else {
                count = 0;
            }
            maxOnes = max(maxOnes, count);
        }

        return maxOnes;
    }
};