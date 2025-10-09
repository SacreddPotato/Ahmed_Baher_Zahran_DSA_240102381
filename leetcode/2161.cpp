#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lessThanPivot;
        vector<int> equalToPivot;
        vector<int> greaterThanPivot;
        vector<int> finalArray;
        
        for (int num: nums) {
            if (num < pivot) {
                lessThanPivot.push_back(num);
            } else if (num > pivot) {
                greaterThanPivot.push_back(num);
            } else {
                equalToPivot.push_back(num);
            }
        }

        finalArray.insert(finalArray.end(), lessThanPivot.begin(), lessThanPivot.end());
        finalArray.insert(finalArray.end(), equalToPivot.begin(), equalToPivot.end());
        finalArray.insert(finalArray.end(), greaterThanPivot.begin(), greaterThanPivot.end());

        return finalArray;
    }
}; // Solved