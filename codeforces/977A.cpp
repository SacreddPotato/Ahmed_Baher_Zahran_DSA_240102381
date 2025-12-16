#include <iostream>

using namespace std;

int performSubtractions(int num, int times) {
    for (int i = 0; i < times; i++) {
        if (num % 10 == 0) {
            num /= 10;
        } else {
            num--;
        }
    }

    return num;
}

int main() {
    int num, times;
    cin >> num >> times;
    cout << performSubtractions(num, times) << "\n";
    return 0;
}