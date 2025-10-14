#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int moves = 0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());

        for (int i = 0; i < students.size(); i++) {
            if (students[i] == seats[i]) {
                continue;
            }
            moves += abs(students[i] - seats[i]);
        }

        return moves;
    }
}; // Solved