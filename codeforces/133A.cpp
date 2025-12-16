#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;

    cin >> str;
    bool h = false;
    for (char c: str) {
        if (c == 'H' || c == 'Q' || c == '9') {
            h = true;
        }
    }

    cout << ((h) ? "YES" : "NO") ;
}