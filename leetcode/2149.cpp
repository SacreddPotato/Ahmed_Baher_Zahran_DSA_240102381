#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> negNums;
        vector<int> posNums;
        vector<int> finalArr;

        for (int num: nums) {
            if (num < 0) {
                negNums.push_back(num);
            } else {
                posNums.push_back(num);
            }
        }

        for (int i = 0; i < posNums.size(); i++) {
            finalArr.push_back(posNums[i]);
            finalArr.push_back(negNums[i]);
        }

        return finalArr;
    }
};