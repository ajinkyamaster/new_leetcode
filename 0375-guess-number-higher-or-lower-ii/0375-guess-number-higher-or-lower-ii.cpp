class Solution {
public:
    int f(int i, int n, vector<vector<int>> & dp) {

        if(i >= n) return 0;

        if(dp[i][n]!=-1) return dp[i][n];

        int ans = INT_MAX;

        for(int r = i; r <= n; r++) {

            int high = r + f(r+1, n, dp);
            int low = r + f(i, r-1, dp);

            ans = min(ans, max(high, low));
        }

        return dp[i][n] = ans;
    }

   int getMoneyAmount(int n) {

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n-1; i>=1; i--) {

            for(int j=i+1; j<=n; j++) {

                int ans = INT_MAX;

                for(int r=i; r<=j; r++) {

                    int high = r + dp[r+1][j];
                    int low = r + dp[i][r-1];

                    ans = min(ans, max(high, low));
                }

                dp[i][j] = ans;
            }
        }

        return dp[1][n];
    }
};