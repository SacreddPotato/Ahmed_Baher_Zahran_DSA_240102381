#include <vector>

using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int evenBinary = 0;
        int oddBinary = 0;
        vector<int> indices;

        do {
            if (n % 2 == 1) {
                indices.push_back(1);
            } else {
                indices.push_back(0);
            }
            n /= 2;
        } while(n > 0);

        for (int i = 0; i < indices.size(); i++) {
            if (indices.at(i) == 1) {
                if (i % 2 == 0) {
                    evenBinary += 1;
                } else {
                    oddBinary += 1;
                }
            }
        }
        return {evenBinary,oddBinary};
    }
};

int main() {
    Solution t;
    t.evenOddBit(50);
    return 0;
}