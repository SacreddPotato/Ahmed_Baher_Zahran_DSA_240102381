#include <iostream>

int main() {
    int solvableProblems = 0;
    int numOfProblems = 0;
    int choice1;
    int choice2;
    int choice3;

    std::cin >> numOfProblems;

    for (int i = 0; i <= numOfProblems; i++) {
        std::cin >> choice1;
        std::cin >> choice2;
        std::cin >> choice3;

        if ((choice1 + choice2 + choice3) >= 2) {
            solvableProblems += 1;
        }
    }

    std::cout << solvableProblems;

    return 0;
}

// Couldn't Solve