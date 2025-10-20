#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// (-b+-sqrt(b^2 -4ac)/2a

bool hasRoots(int a, int b, int c) {
    if ((b*b - 4*a*c) < 0) {
        return false;
    }
    return true;
};

vector<double> computeRoots(int a,int b,int c) { // We return a vector because C++ doesn't let us return arrays
    double root1 = ((-b+sqrt(b*b-4*a*c))/2*a);
    double root2 = ((-b-sqrt(b*b-4*a*c))/2*a);

    return {root1,root2};
}


int main() {
    int a,b,c;
    cout << "Enter first number of the equation:\n";
    cin >> a;

    cout << "Enter second number of the equation:\n";
    cin >> b;

    cout << "Enter third number of the equation:\n";
    cin >> c;

    if (hasRoots(a,b,c)) {
        vector<double> roots = computeRoots(a,b,c);
        cout << "Two real roots: " << roots.at(0) << ", " << roots.at(1);
    } else {
        cout << "Complex Roots.";
    }
    
    return 0;
}