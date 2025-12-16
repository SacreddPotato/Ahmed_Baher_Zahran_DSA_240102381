#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int minNumberOfCoins(vector<int> coins) {
    sort(coins.begin(), coins.end());
    reverse(coins.begin(), coins.end());
    
    int nCoins = 0;
    int n = 0;
    while (true) {
        int minSum = 0;
        int remainingSum = 0;
        for (int i = 0; i <= n; i++) {
            minSum += coins[i];
        }

        for (int j = n + 1; j < coins.size(); j++) {
            remainingSum += coins[j];
        }

        if (minSum > remainingSum) {
            return n + 1;
        }
        n++;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << minNumberOfCoins(coins) << "\n";    

    return 0;
}