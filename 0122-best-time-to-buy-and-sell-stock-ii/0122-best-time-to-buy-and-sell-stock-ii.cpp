class Solution {
public:
    int f(vector<int>& prices, int i, int buy, vector<vector<int>> &dp){

        if(i>=prices.size()) return 0;
        int profit;

        if(dp[i][buy]!= -1) return dp[i][buy];
        
        if(buy){
            profit = max(prices[i] + f(prices, i+1, 0, dp), 0 + f(prices, i+1, 1, dp));
        }
        else{
            profit = max(-prices[i] + f(prices, i+1, 1, dp), 0 + f(prices, i+1, 0, dp));
        }

        return  dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(prices, 0, 0, dp);
    }
};