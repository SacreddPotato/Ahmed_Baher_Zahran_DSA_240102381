#include <iostream>

using namespace std;

int main() {
    int first;
    int second;
    int third;
    int helper1;
    int helper2;
    
    cout << "Enter first number:\n";
    cin >> first;
    cout << "Enter second number:\n";
    cin >> second;
    cout << "Enter third number:\n";
    cin >> third;

    if (first > second) {
        if (third > first) {
            helper1 = first;
            first = third;
            third = helper1;
        } else if (third > second) {
            helper1 = second;
            second = third;
            third = helper1;
        } 

    } else if (second > first) {
        if (third > second) {
            helper1 = third;
            third = first;
            first = helper1;
        } else if (third > first) {
            helper1 = second;
            second = third;
            third = first;
            first = helper1;
        } else { 
            helper1 = first;
            first = second;
            second = helper1;
        }
    }
    cout << "Sorted numbers: " << first << ", " << second << ", " << third << "\n";

    return 0;
}