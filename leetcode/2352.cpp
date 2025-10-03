#include <vector>

using namespace std;

// class Solution {
// public:
//     int equalPairs(vector<vector<int>>& grid) {
//         int numOfEqualPairs = 0;
//         for (vector<int> row: grid) {
//             for (vector<int>& inversedRows: transpose(grid)) {
//                 if (row == inversedRows) {
//                     numOfEqualPairs++;
//                 }
//             }
//         }
//         return numOfEqualPairs;
//     }

//     vector<vector<int>> transpose(vector<vector<int>> grid) {
//         vector<vector<int>> transpose;

//         vector<int> newColumn;
//         for (int i = 0; i < grid.size(); i++) {
//             newColumn.clear();
//             for (int j = 0; j < grid.size(); j++) { 
//                 newColumn.push_back(grid.at(j)[i]);
//             }
//             transpose.push_back(newColumn);
//         }

//         return transpose;
//     }


// }; // Solved - attempt 1 (too slow)

class Solution {
    public:
    int equalPairs(vector<vector<int>>& grid) {
        int numOfEqualPairs = 0;
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool isEqual = true;
                for (int k = 0; k < n; k++) {
                    if (grid[i][k] != grid[k][j]) { // Mostly trial and error
                        isEqual = false;
                        break;
                    }
                }
                if (isEqual) {
                    numOfEqualPairs++;
                }
            }
        }
        return numOfEqualPairs;
    }
}; // Solved - attempt 2 