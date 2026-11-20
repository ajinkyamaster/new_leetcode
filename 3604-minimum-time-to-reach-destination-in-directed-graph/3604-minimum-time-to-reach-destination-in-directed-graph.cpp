class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int, int>>> adj(n);

        // Use const auto& to avoid copying vectors in each iteration
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2], edge[3]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        vector<long long> dist(n, LLONG_MAX);

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node])
                continue;

            if (node == n - 1)
                return time;

            for (const auto& [neigh, st, end] : adj[node]) {
                long long depart = max(time, (long long)st);

                if (depart <= end) {
                    long long newTime = depart + 1;

                    if (newTime < dist[neigh]) {
                        dist[neigh] = newTime;
                        pq.push({newTime, neigh});
                    }
                }
            }
        }

        return -1;
    }
};