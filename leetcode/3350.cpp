#include <vector>
#include <cmath>

using namespace std;

struct SubarrayInfo {
    vector<int> subarray;
    int startIndex;
};

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<SubarrayInfo> subarrays;
        int k = 1;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> subarray;
            subarray.push_back(nums.at(i));
            
            for (int right = i + 1; right < nums.size(); right++) {
                if (nums.at(right) > nums.at(right - 1)) {
                    subarray.push_back(nums.at(right));
                    subarrays.push_back({subarray, i});
                } else {
                    break;
                }
            }
        }

        for (auto info1 : subarrays) {
            for (auto info2 : subarrays) {
                if (info1.startIndex + info1.subarray.size() == info2.startIndex 
                    && info1.subarray.size() == info2.subarray.size()) {
                    k = max(k, (int)info1.subarray.size());
                }
            }
        }

        return k;
    }
};

int main() {
    Solution s;
    vector<int> test = {1,2,3,4,4,4,4,5,6,7};
    s.maxIncreasingSubarrays(test);

    return 0;
}

// works.... but time complexity is o(n^4)!!!