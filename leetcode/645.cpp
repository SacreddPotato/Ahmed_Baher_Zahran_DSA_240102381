#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[0] == nums[1]) {
                    if (nums[0] != 1) {
                        return {nums[0], nums[0] - 1};
                    } else {
                        return {nums[0], nums[0] + 1};
                    }
                }
                if (nums[i] + 1 != nums[i+1]) {
                    return {nums[i+1], nums[i] + 1};
                }
            }

        return {};
    }
};