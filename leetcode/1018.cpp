#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int counter = 0; 
        vector<bool> ans;

        for (int i = 0; i < nums.size(); i++) {
            long long num = 0;
            int k = counter;
            for (int j = 0; j <= i; j++) {
                num %= 5;
                num += nums[j]*pow(2,k);
                k--;
            }
            ans.push_back(num % 5 == 0);
            counter++;
        }

        return ans;
    }
};

int main() {
    vector<int> test = {0,1,1,1,1,1};
    int s = Solution().prefixesDivBy5(test).size();
    return 0;
}