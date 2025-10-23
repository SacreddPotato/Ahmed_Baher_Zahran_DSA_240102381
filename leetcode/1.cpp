#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> elementAndIndex;

        for (int i = 0; i < nums.size(); i++) {
            int difference = target-nums.at(i);

            if (elementAndIndex.count(difference)) {
                return {i, elementAndIndex[difference]};
            }

            elementAndIndex[nums.at(i)] = i;
        }
        return {0,0};
    }
};