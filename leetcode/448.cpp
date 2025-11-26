#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> noDuplicates;
        vector<int> finalArr;

        for (int i = 0; i < nums.size(); i++) {
            noDuplicates.insert(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (noDuplicates.find(i + 1) == noDuplicates.end()) {
                finalArr.push_back(i + 1);
            }
        }

        return finalArr;
    }
};