#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;

        for (string operation: operations) {
            if (operation.at(0) == '+' || operation.at(operation.length()-1) == '+') {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }
};