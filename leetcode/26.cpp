#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> copy = nums;
        int k = 0;

        for (int i = 0; i < copy.size(); i++) {            
            if (copy.at(i + 1) == copy.at(i)) {
                k+=1;
                nums.erase(nums.begin() + (i + 1));
            }
        }
        return k;

        
    }
};