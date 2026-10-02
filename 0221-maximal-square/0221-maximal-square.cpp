class Solution {
public:
    // int solve(int i, int j, vector<vector<char>>& matrix,
    //           vector<vector<int>>& dp) {

    //     if(i < 0 || j < 0)
    //         return 0;

    //     if(matrix[i][j] == '0')
    //         return 0;

    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     int top = solve(i - 1, j, matrix, dp);
    //     int left = solve(i, j - 1, matrix, dp);
    //     int diagonal = solve(i - 1, j - 1, matrix, dp);

    //     return dp[i][j] =
    //         1 + min({top, left, diagonal});
    // }

    int maximalSquare(vector<vector<char>>& matrix) {

         int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int maxSide = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == '1') {

                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] =
                            1 + min({
                                dp[i-1][j],
                                dp[i][j-1],
                                dp[i-1][j-1]
                            });
                    }

                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        return maxSide * maxSide;
    }
};