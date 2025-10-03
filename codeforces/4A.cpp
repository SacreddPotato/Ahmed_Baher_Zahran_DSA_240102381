#include <iostream>

int main() {
    int num;

    std::cin >> num;
    std::cout << ((num % 2 == 0 && num != 2) ? "YES" : "NO");
    
    return 0;
}

// Solved