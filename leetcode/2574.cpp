#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ansArray;

        for (int i = 0; i < nums.size(); i++) {
            int left = 0;
            int right = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (j < i) {
                    left += nums.at(j);
                }
                if (j > i) {
                    right += nums.at(j);
                }
            }
            ansArray.push_back(abs(left - right));
        }   
        
        return ansArray;
    }
};