class Solution {
public:
    long long modPow(long long base, long long exp) {
        long long MOD = 1e9 + 7;
        long long result = 1;

        while (exp > 0) {
            // If exponent is odd, multiply result
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }

            // Square the base
            base = (base * base) % MOD;

            // Divide exponent by 2
            exp /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long MOD = 1e9 + 7;

        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long ans = modPow(5, evenPositions);

        ans = (ans * modPow(4, oddPositions)) % MOD;

        return ans;
    }
};