class Solution {
public:
    // int f(int i, vector<int>& nums, int prev, vector<vector<int>>& dp) {

    //     if (i == 0) {
    //         if (nums[0] >= prev)
    //             return 1;
    //         return INT_MAX;
    //     }

    //     if (dp[i][prev] != -1) {
    //         return dp[i][prev];
    //     }

    //     int take = INT_MAX;
    //     int notTake;

    //     if (nums[i] + i >= prev) {

    //         take = 1 + f(i - 1, nums, i, dp);
    //     }

    //     notTake = 0 + f(i - 1, nums, prev, dp);

    //     return dp[i][prev] = min(take, notTake);
    // }

    int jump(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f(n-1, nums, n-1, dp);

        const int INF = 1e9;

        vector<int> prevDP(n, INF);
        vector<int> currDP(n, INF);

        // Base case: i = 0
        for (int prev = 1; prev < n; prev++) {
            if (nums[0] >= prev)
                prevDP[prev] = 1;
        }

        // i = 1 to n-2
        for (int i = 1; i < n - 1; i++) {

            for (int prev = i + 1; prev < n; prev++) {

                int take = INF;

                if (nums[i] + i >= prev) {
                    take = 1 + prevDP[i];
                }

                int notTake = prevDP[prev];

                currDP[prev] = min(take, notTake);
            }

            // Move current row to previous row
            prevDP = currDP;

            // Reset current row
            fill(currDP.begin(), currDP.end(), INF);
        }

        return prevDP[n - 1];
    }
};