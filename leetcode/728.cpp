#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> numToDigits;
        vector<int> ans;

        for (int i = left; i <= right; i++) {
            numToDigits.clear();
            bool helper = true;
            int num = i;

            while (num > 0) {
                if (num % 10 == 0) {
                    helper = false;
                    break;
                }
                numToDigits.push_back(num % 10);
                num /= 10;
            }
            
            for (int digit: numToDigits) {
                if (!(i % digit == 0)) {
                    helper = false;
                    break;
                }
            }

            if (helper) {
                ans.push_back(i);
            }
        }    
        
        return ans;
    }
};

int main() {
    Solution s;
    s.selfDividingNumbers(1,22);

    return 0;
}