#include <vector>

using namespace std;

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxArea = 0;
//         int n = height.size();

//         for (int i = 0; i < n; i++) {
//             int area = 0;
//             for (int j = i+1; j < n; j++) {
//                 area = min(height[i],height[j])*(j-i);
//                 maxArea = max(maxArea,area);
//             }
//         }
//         return maxArea;
//     }
// }; // Attempt 1, Solved but too slow.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() -1;

        while (left < right) {
            int area = min(height[left], height[right])*(right-left);
            maxArea = max(area,maxArea);

            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }

        }

        return maxArea;
    }
}; // Attempt 2, Solved.