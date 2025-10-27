#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int leftLasers;
        int rightLasers;
        int lasers = 0;

        for (int i = 0; i < bank.size(); i++) {
            leftLasers = calculateAmountOfLasers(bank.at(i));
            if (leftLasers == 0) {continue;}
            for (int j = i + 1; j < bank.size(); j++) {
                rightLasers = calculateAmountOfLasers(bank.at(j));
                if (rightLasers == 0) {
                    continue;
                }
                lasers += leftLasers * rightLasers;
                break;
            }
        }

        return lasers; 
    }

    int calculateAmountOfLasers(string floorPlan) {
        int lasers = 0;
        for (char c: floorPlan) {
            if (c == '1') {
                lasers += 1;
            }
        }
        return lasers;
    }
};

int main() {
    Solution s;
    vector<string> bank = {"011001","000000","010100","001000"};

    s.numberOfBeams(bank);

    return 0;
}