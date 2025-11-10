#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == 1) {
                vector<int> row = vector<int>(i+1, 1);
                triangle.push_back(row);
                continue;
            }
            vector<int> row = vector<int>(i+1,0);
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row[j] = 1;
                    continue;
                }
                row[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};

int main() {
    Solution s;
    s.generate(5);

    return 0;
}