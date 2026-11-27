
class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[4][3][5001];

    int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
    int dy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};

    int f(int i, int j, int n) {

        // Invalid positions
        if (i < 0 || i >= 4 || j < 0 || j >= 3)
            return 0;

        // Invalid keypad buttons
        if (i == 3 && (j == 0 || j == 2))
            return 0;

        // Base case
        if (n == 0)
            return 1;

        // Already calculated
        if (dp[i][j][n] != -1)
            return dp[i][j][n];

        long long ans = 0;

        for (int k = 0; k < 8; k++) {
            ans = (ans + f(i + dx[k], j + dy[k], n - 1)) % MOD;
        }

        return dp[i][j][n] = ans;
    }

    int knightDialer(int n) {

        memset(dp, -1, sizeof(dp));

        long long sum = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {

                if (i == 3 && (j == 0 || j == 2))
                    continue;

                sum = (sum + f(i, j, n - 1)) % MOD;
            }
        }

        return sum;
    }
};
