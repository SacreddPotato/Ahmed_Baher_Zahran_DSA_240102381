#include <vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = 1;
        for (int num: nums) {
            if (num == 0) return 0;
            n = (n*num > 0) ? 1 : -1;
        }      

        return (n > 0) ? 1 : -1;
    }
};