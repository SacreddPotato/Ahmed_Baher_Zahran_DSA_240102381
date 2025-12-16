#include <iostream>

using namespace std;

int calculateLoan(int initialCost, int initialMoney, int num) {
    int loan = 0;
    for (int i = 0; i < num; i++) {
        if (initialMoney - (i+1)*initialCost < 0) {
            loan += (i+1)*initialCost;
        } else {
            initialMoney -= (i+1)*initialCost;
        }
    }

    return (loan > initialMoney) ? loan - initialMoney : 0;
}

int main() {
    int initialCost, initialMoney, num;
    cin >> initialCost >> initialMoney >> num;
    cout << calculateLoan(initialCost, initialMoney, num) << "\n";
    return 0;
}