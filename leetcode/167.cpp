#include <map>
#include <vector> 

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> numAndIndex;
        int difference;
        
        for (int i = 0; i < numbers.size(); i++) {
            difference = target - numbers[i];

            if (numAndIndex.count(difference)) {
                return {numAndIndex[difference] + 1, i+1};
            } 

            numAndIndex[numbers[i]] = i;
        }

        return {0,0};
    }
};