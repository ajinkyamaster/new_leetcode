class Solution {
public:
    int minFee = 1e9;

    void solve(int src, int dest,
               vector<vector<pair<int, int>>> &adj,
               vector<int> &vis,
               int time, int fee,
               vector<int>& passingFees,
               int maxTime,
               vector<vector<int>>& dp) {

        fee += passingFees[src];

        // Time limit exceeded
        if (time > maxTime)
            return;

        // Already worse than an answer we found
        if (fee >= minFee)
            return;

        // Same node + same time was reached with cheaper/equal fee
        if (dp[src][time] <= fee)
            return;

        dp[src][time] = fee;

        // Destination reached
        if (src == dest) {
            minFee = fee;
            return;
        }

        vis[src] = 1;

        for (auto neigh : adj[src]) {

            int next = neigh.first;
            int travelTime = neigh.second;

            int newTime = time + travelTime;

            if (!vis[next] && newTime <= maxTime) {

                solve(next, dest,
                      adj, vis,
                      newTime, fee,
                      passingFees,
                      maxTime, dp);
            }
        }

        // Backtrack
        vis[src] = 0;
    }

    int minCost(int maxTime,
                vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();

        vector<vector<pair<int, int>>> adj(n);

        // Build graph
        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> vis(n, 0);

        // dp[node][time] = minimum fee
        vector<vector<int>> dp(
            n, vector<int>(maxTime + 1, 1e9)
        );

        solve(0, n - 1,
              adj, vis,
              0, 0,
              passingFees,
              maxTime, dp);

        return minFee >= 1e9 ? -1 : minFee;
    }
};