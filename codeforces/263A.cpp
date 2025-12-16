#include <vector>
#include <iostream>

using namespace std;

int beautifyMatrix(vector<vector<int>> matrix) {
    int moves = 0;
    loopStart:
    for (int i = 0; i < matrix.size(); i++) { // row
        for (int j = 0; j < matrix.size(); j++) { // column
            if (matrix[i][j] == 1 && i == 2 && j == 2) {
                return moves;
            } else if (matrix[i][j] == 1) {
                if (i < 2) {
                    matrix[i][j] = 0;
                    moves += 2 - i;
                    matrix[2][j] = 1;
                    i = 0;
                    goto loopStart;
                } else if (i > 2) {
                    matrix[i][j] = 0;
                    moves += i - 2;
                    matrix[2][j] = 1;
                    i = 0;
                    goto loopStart;
                }

                if (j < 2) {
                    matrix[i][j] = 0;
                    moves += 2 - j;
                    matrix[i][2] = 1;
                    goto loopStart;
                } else if (j > 2) {
                    matrix[i][j] = 0;
                    moves += j - 2;
                    matrix[i][2] = 1;
                    goto loopStart;
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix(5, vector<int>(5, 0));
    matrix[2][1] = 1;
    cout << beautifyMatrix(matrix) << "\n";

    return 0;
}