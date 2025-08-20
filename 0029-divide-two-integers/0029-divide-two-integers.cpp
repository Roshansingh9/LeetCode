class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        bool sign = (dividend >= 0) == (divisor >= 0);

        long n = labs(dividend);
        long d = labs(divisor);
        long ans = 0;

        while (n >= d) {
            long count = 0;
            while (n >= (d << (count + 1))) count++;
            ans += (1L << count);
            n -= (d << count);
        }

        if (ans > INT_MAX) return sign ? INT_MAX : INT_MIN;
        return sign ? ans : -ans;
    }
};
