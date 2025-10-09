#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        for (int i = 0; i < candies.size(); i++) {
            bool helper = true;
            for (int j = 0; j < candies.size(); j++) {
                if (j == i) {
                    continue;
                }
                if (!((candies.at(i) + extraCandies) >= candies.at(j))) {
                    helper = false;
                    break;
                }
            }
            ans.push_back(helper);
        }
        return ans;
    }
};