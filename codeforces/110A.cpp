#include <iostream>

using namespace std;

bool isLuckyNumber(int num) {
    int c = 0;
    while (num > 0) {
        if (num % 10 == 7 || num % 10 == 4) {
            c++;
        }

        num /= 10;
    }

    return (c == 7 || c == 4);
}


int main() {
    int num;

    cin >> num;
    if (isLuckyNumber(num)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}