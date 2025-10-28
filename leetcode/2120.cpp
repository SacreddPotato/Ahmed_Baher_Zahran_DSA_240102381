#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> steps;
        for (int i = 0; i < s.size(); i++) {
            int x = startPos[1];
            int y = startPos[0];
            int count = 0;
            for (int j = i; j < s.size(); j++) {
                    switch (s.at(j)) {
                    case 'L':
                        if (--x < 0) {
                            goto end_loop;
                        }
                        count +=1;
                        break;
                    case 'R':
                        if (++x >= n) {
                            goto end_loop;
                        }
                        count+=1;
                        break;
                    case 'U':
                        if (--y < 0) {
                            goto end_loop;
                        }
                        count+=1;
                        break;
                    case 'D':
                        if (++y >= n) {
                            goto end_loop;
                        }
                        count+=1;
                        break;
                }
            }
            end_loop:;
            steps.push_back(count);
        }

        return steps;
    }
};

int main() {
    Solution s;
    vector<int> startPos = {0,1};

    s.executeInstructions(3, startPos, "RRDDLU");

    return 0;
}