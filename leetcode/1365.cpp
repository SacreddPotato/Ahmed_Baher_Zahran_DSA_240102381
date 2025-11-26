#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count;
        vector<int> finalArr;

        for (int i = 0; i < nums.size(); i++) {
            count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] <= nums[j]) continue;

                if (nums[i] > nums[j]) count++;
            }

            finalArr.push_back(count);
        }

        return finalArr;
    }
};