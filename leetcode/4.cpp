#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArr;
        int biggestArrSize  = max(nums1.size(), nums2.size());

        for (int i = 0; i < biggestArrSize; i++) {
            if (i < nums1.size()) {
                mergedArr.push_back(nums1[i]);
            }

            if (i < nums2.size()) {
                mergedArr.push_back(nums2[i]);
            }
        }

        sort(mergedArr.begin(), mergedArr.end());

        if (mergedArr.size() % 2 == 0) {
            return (mergedArr[mergedArr.size()/2]+mergedArr[-1+(mergedArr.size()/2)])/(double)2;
        } else {
            return mergedArr[mergedArr.size()/2];
        }
    }
};