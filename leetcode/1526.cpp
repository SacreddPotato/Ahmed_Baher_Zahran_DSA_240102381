#include <vector> 

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        vector<int> initial = vector<int>(target.size(),0);
        int count = 0;
        
        for (int i = 0; i < target.size(); i++) {
            while (true) {
                if (target[i] <= initial[i]) {
                    break;
                }
                int left = i;
                int right = i + 1;
                for (right; right < target.size(); right ++) {
                    if (target[right] > initial[i]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
                for (left; left < right; left++) {
                    initial[left] += 1;
                }
                count += 1;
            }
        }
        
        return count;
    }
};

int main() {
    Solution s;

    vector<int> test = {3,1,5,4,2};

    s.minNumberOperations(test);

    return 0;
} // "Solved", but too slow! O(n^2)