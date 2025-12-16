#include <vector>
#include <iostream>

using namespace std;

bool isInEqullibrium(vector<vector<int>> coords) {
    int x = 0;
    int y = 0;
    int z = 0;

    for (vector<int> coord: coords) {
        x += coord[0];
        y += coord[1];
        z += coord[2];
    }

    return (x == 0 && y == 0 && z == 0);
}


int main() {
    int n;
    cin >> n;

    vector<vector<int>> coords(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> coords[i][0] >> coords[i][1] >> coords[i][2];
    }

    if (isInEqullibrium(coords)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}