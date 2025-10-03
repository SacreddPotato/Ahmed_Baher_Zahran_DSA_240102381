#include <iostream>
#include <string>

int main() {
    int x = 0;
    int numOfOperations;
    std::string operation;
    std::cin >> numOfOperations;

    for (int i = 0; i <= numOfOperations; i++) {
        std::cin >> operation;
        for (char c : operation) {
            switch (c) {
                case '+':
                    x++;
                    goto exitLoop;
                case '-':
                    x--;
                    goto exitLoop;
                default:
                    break;
            }
        }
        exitLoop:
    }

    std::cout << x;

    return 0;
}

// Couldn't solve