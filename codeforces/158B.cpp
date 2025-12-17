#include <vector>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int minTaxis(vector<int> groupSizes) { // Groups are >= 1, <= 4
    set<int> usedIndices;
    int taxis = 0;

    for (int i = 0; i < groupSizes.size(); i++) {
        int currGroup = groupSizes[i];
        for (int j = 0; j < groupSizes.size(); j++) {
            if (j == i) continue;
            if (usedIndices.count(i) > 0) goto nextGroup;
            if (usedIndices.count(j) == 0 && currGroup + groupSizes[j] <= 4) {
                currGroup += groupSizes[j];
                usedIndices.insert(j);
            }

            if (currGroup == 4) break;
        }

        usedIndices.insert(i);
        taxis++;
        nextGroup:
    }

    return taxis;
}

int main() {
    int n;
    cin >> n;
    vector<int> groupSizes(n);
    for (int i = 0; i < n; i++) {
        cin >> groupSizes[i];
    }

    cout << minTaxis(groupSizes) << endl;

    return 0;
}