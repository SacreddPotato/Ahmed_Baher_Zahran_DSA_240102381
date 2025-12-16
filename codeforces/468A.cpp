#include <iostream>

using namespace std;

int f(int n) { // f(n) = -1 + 2 - 3 + 4 ..... (-1)^n * n
    int y = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            y += i;
        } else {
            y -= i;
        }
    }

    return y;
}

int main() {
    int n;
    cin >> n;

    cout << f(n) << "\n";

    return 0;
} // Time limit exceeded