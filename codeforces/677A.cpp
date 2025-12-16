#include <iostream>
#include <vector>

using namespace std;

int minWidth(vector<int> friends, int h) {
    int width = 0;

    for (int f: friends) {
        (f > h) ? width += 2 : width ++;
    }

    return width;
}

int main() {
    int n;
    int h;
    cin >> n >> h;

    vector<int> friends(n);
    for (int i = 0; i < n; i++) {
        cin >> friends[i];
    }

    cout << minWidth(friends, h) << "\n";
    return 0;
}