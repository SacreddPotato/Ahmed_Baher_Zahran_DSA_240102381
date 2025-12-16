#include <string>
#include <iostream>

using namespace std;

string removeStones(string stones) {
    for (int i = 0; i < stones.size(); i++) {
        bool helper = false;
        for (int j = i + 1; j < stones.size(); j++) {
            if (stones[i] == stones[j] && j + 1 == stones.size()) {
                j++;
                goto erase;
            }
            if (stones[i] == stones[j]) {
                helper = true;
                continue;
            } else {
                if (helper) {
                    erase:
                    stones.erase(i+1, j - i - 1);
                    i--;
                    helper = false;
                }

                break;
            }
        }
    }

    return stones;
}

int main() {
    cout << removeStones("RRRRBRR") << "\n";

    return 0;
}