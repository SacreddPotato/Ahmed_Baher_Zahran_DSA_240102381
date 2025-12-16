#include <vector>

using namespace std;

int nextRound(int n, int k,vector<int> scores) {
    int num = 0;

    for (int score: scores) {
        if (score >= k) {
            num++;
        }
    }

    return num;
}