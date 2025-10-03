class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const long long MOD = 1e9 + 7;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = 1;
        }

        for (int _ = 0; _ < k; _++) {
            for (int i = 1; i < n; i++) {
                arr[i] = (arr[i] + arr[i-1]) % MOD;
            }
        }
        return (int)(arr[n-1] % MOD);
    }
}; //   Solved