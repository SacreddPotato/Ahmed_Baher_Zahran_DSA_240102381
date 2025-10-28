#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long sumOfPrimes = 0;
        long long sumOfNonPrimes = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (isPrime(i)) {
                sumOfPrimes += nums[i];
            } else {
                sumOfNonPrimes += nums[i];
            }
        }

        return abs(sumOfNonPrimes - sumOfPrimes);
    }

    bool isPrime(int n) {
        if (n == 0 || n == 1) {return false;};
        if (n == 2) {return true;};
        if (n % 2 == 0) {return false;};

        for (int i = 3; i*i <= n; i+=2) {
            if (n % i == 0) {return false;};
        }
        return true;
    }
};