#include <iostream>

using namespace std;

int calcYearsUntilHeavier(int a, int b, int years = 0) { // a is always less than b, a gets tripled every "year", b only gets doubled.
    if (a > b) {
        return years;
    }

    return calcYearsUntilHeavier(a*3, b*2, ++years);
}

int main() {
    cout << calcYearsUntilHeavier(4, 7) << "\n";

    return 0;
}