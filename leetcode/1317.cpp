#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int diff;
        int temp;
        bool h = true;
        for (int i = 1; i < n; i++) {
            h = true;
            diff = n - i;
            temp = diff;
            while (temp > 0) {
                if (temp % 10 == 0) {
                    h = false;
                    break;
                }
                temp /= 10;
            }
            if (!h) continue;

            temp = i;
            while (temp > 0) {
                if (temp % 10 == 0) {
                    h = false;
                    break;
                }
                temp /= 10;
            } 

            if (!h) continue;

            return {i, diff};
        }

        return {};
    }
};

int main() {
    Solution sol;
    sol.getNoZeroIntegers(11);
}