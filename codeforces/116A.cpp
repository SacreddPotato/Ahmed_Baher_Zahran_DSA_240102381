#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int minCapacity(vector<vector<int>> routes) {  // Routes[i] = route, route[0] = amount to leave, route[1] = amount to enter
    int minCapacity = 0;
    int currPassengers = 0;

    for (vector<int> route: routes) {
        currPassengers += route[1];
        currPassengers -= route[0];

        minCapacity = max(minCapacity, currPassengers);
    }

    return minCapacity;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> routes(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> routes[i][0] >> routes[i][1];
    }
    cout << minCapacity(routes) << "\n";

    return 0;
}