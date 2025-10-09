#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 1) { // Check for 1xn matrices
            vector<int> copy = board[0];
            for (int j = 0; j < board[0].size(); j++) {
                int sum = 0;
                if (j - 1 >= 0) sum += copy[j - 1];
                if (j + 1 < board[0].size()) sum += copy[j + 1];
                
                if (sum == 2 && copy[j] == 1) {
                    board[0][j] = 1;
                } else if (sum == 3 && copy[j] == 0) {
                    board[0][j] = 1;
                } else {
                    board[0][j] = 0;
                }
            }
            return;
        }
        if (board[0].size() == 1) { // Check for nx1 matrices
            vector<int> copy(board.size());
            for (int i = 0; i < board.size(); i++) {
                copy[i] = board[i][0];
            }
            
            for (int i = 0; i < board.size(); i++) {
                int sum = 0;
                if (i - 1 >= 0) sum += copy[i - 1];
                if (i + 1 < board.size()) sum += copy[i + 1];
                
                if (sum == 2 && copy[i] == 1) {
                    board[i][0] = 1;
                } else if (sum == 3 && copy[i] == 0) {
                    board[i][0] = 1;
                } else {
                    board[i][0] = 0;
                }
            }
            return;
        }
        vector<vector<int>> copy = board;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int sum = 0;
                if (i - 1 >= 0 && i + 1 <= board.size() - 1) {
                    if (j - 1 >= 0 && j + 1 <= board.at(0).size() - 1) {
                        sum += copy.at(i-1).at(j-1)
                             + copy.at(i-1).at(j)
                             + copy.at(i-1).at(j+1)
                             + copy.at(i).at(j-1)
                             + copy.at(i).at(j+1)
                             + copy.at(i+1).at(j-1)
                             + copy.at(i+1).at(j)
                             + copy.at(i+1).at(j+1);
                    } else if (j - 1 < 0) {
                        sum += copy.at(i-1).at(j)
                             + copy.at(i-1).at(j+1)
                             + copy.at(i).at(j+1)
                             + copy.at(i+1).at(j)
                             + copy.at(i+1).at(j+1);
                    } else if (j + 1 >= board.at(0).size()) {
                        sum += copy.at(i-1).at(j-1)
                             + copy.at(i-1).at(j)
                             + copy.at(i).at(j-1)
                             + copy.at(i+1).at(j-1)
                             + copy.at(i+1).at(j);
                    }
                } else if (i - 1 < 0) {
                    if (j - 1 >= 0 && j + 1 <= board.at(0).size() - 1) {
                        sum += copy.at(i).at(j-1)
                             + copy.at(i).at(j+1)
                             + copy.at(i+1).at(j-1)
                             + copy.at(i+1).at(j)
                             + copy.at(i+1).at(j+1);
                    } else if (j - 1 < 0) {
                        sum += copy.at(i).at(j+1)
                             + copy.at(i+1).at(j)
                             + copy.at(i+1).at(j+1);
                    } else if (j + 1 >= board.at(0).size()) {
                        sum += copy.at(i).at(j-1)
                             + copy.at(i+1).at(j-1)
                             + copy.at(i+1).at(j);
                    }
                } else if (i + 1 >= board.size()) {
                    if (j - 1 >= 0 && j + 1 <= board.at(0).size() - 1) {
                        sum += copy.at(i-1).at(j-1)
                             + copy.at(i-1).at(j)
                             + copy.at(i-1).at(j+1)
                             + copy.at(i).at(j-1)
                             + copy.at(i).at(j+1);
                    } else if (j - 1 < 0) {
                        sum += copy.at(i-1).at(j)
                             + copy.at(i-1).at(j+1)
                             + copy.at(i).at(j+1);
                    } else if (j + 1 >= board.at(0).size()) {
                        sum += copy.at(i-1).at(j-1)
                             + copy.at(i-1).at(j)
                             + copy.at(i).at(j-1);
                    }
                }
                if ((sum == 2 || sum == 3) && copy.at(i).at(j) == 1) {
                    board.at(i).at(j) = 1;
                } else if (sum == 3 && copy.at(i).at(j) == 0) {
                    board.at(i).at(j) = 1;
                } else {
                    board.at(i).at(j) = 0;
                }
            }
        }

    }
}; // Solved, but it looks so so bad :(