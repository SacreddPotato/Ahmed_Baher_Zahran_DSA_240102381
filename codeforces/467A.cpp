#include <vector>
#include <iostream>

using namespace std;

int freeRooms(vector<vector<int>> rooms) {
    int freeRooms = 0;

    for (auto room: rooms) {
        if (room[1] - room[0] >= 2) {
            freeRooms++;
        }
    }

    return freeRooms;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> rooms(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> rooms[i][0] >> rooms[i][1];
    }

    cout << freeRooms(rooms) << "\n";

    return 0;
}