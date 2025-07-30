class Solution {
public:
    const int MOD = 1000000007;

    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans1 = modPow(5, even, MOD);
        long long ans2 = modPow(4, odd, MOD);

        return (ans1 * ans2) % MOD;
    }
};
