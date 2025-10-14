#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = numeric_limits<int>::min();

        for (int i = 0; i < energy.size(); i++) {
            int sum = 0;
            int n = 0;
            while (true) {
                try {
                    sum += energy.at(i + k*n);
                    n++;
                }
                catch(const exception& e) {
                    break;
                }
            }
            ans = max(sum,ans);
        }

        return ans;
    }
}; // Solved, But too high of a time complexity
