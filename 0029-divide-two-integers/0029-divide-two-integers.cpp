class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to positive using long long
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quotient = 0;

        // Try powers of 2 from largest to smallest
        for (int i = 31; i >= 0; i--) {

            if ((b << i) <= a) {

                // Subtract divisor * 2^i
                a -= (b << i);

                // Add 2^i to quotient
                quotient += (1LL << i);
            }
        }

        if (negative)
            quotient = -quotient;

        return (int)quotient;
    }
};