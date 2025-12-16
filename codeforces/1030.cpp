#include <string>
#include <iostream>
#include <vector>

using namespace std;

string isEasyOrHard(vector<int> opinion) {
    for (int o: opinion) {
        if (o == 1) {
            return "HARD";
        }
    }

    return "EASY";
}

int main() {
    int n;
    cin >> n;

    vector<int> opinion(n);
    for (int i = 0; i < n; i++) {
        cin >> opinion[i];
    }

    cout << isEasyOrHard(opinion) << "\n";
    return 0;
}