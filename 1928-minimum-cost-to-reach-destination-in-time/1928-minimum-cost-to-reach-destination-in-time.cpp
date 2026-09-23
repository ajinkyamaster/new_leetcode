class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
            vector<int>& passingFees) {

    int n = passingFees.size();

    vector<vector<pair<int,int>>> adj(n);

    for (auto &e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    // dp[node][time] = minimum fee
    vector<vector<int>> dp(n, vector<int>(maxTime + 1, 1e9));

    // {fee, node, time}
    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
    > pq;

    dp[0][0] = passingFees[0];
    pq.push({passingFees[0], 0, 0});

    while (!pq.empty()) {

        auto [fee, node, time] = pq.top();
        pq.pop();

        if (node == n - 1)
            return fee;

        if (fee > dp[node][time])
            continue;

        for (auto [next, travelTime] : adj[node]) {

            int newTime = time + travelTime;

            if (newTime > maxTime)
                continue;

            int newFee = fee + passingFees[next];

            if (newFee < dp[next][newTime]) {
                dp[next][newTime] = newFee;

                pq.push({
                    newFee,
                    next,
                    newTime
                });
            }
        }
    }

    return -1;
}
};