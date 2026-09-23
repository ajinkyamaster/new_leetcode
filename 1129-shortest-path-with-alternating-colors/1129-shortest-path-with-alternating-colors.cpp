class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges
    ) {
        // {neighbor, color}
        // 0 -> red
        // 1 -> blue
        vector<vector<pair<int, int>>> adj(n);

        for (auto edge : redEdges) {
            adj[edge[0]].push_back({edge[1], 0});
        }

        for (auto edge : blueEdges) {
            adj[edge[0]].push_back({edge[1], 1});
        }

        // dist[node][color]
        // Minimum distance to reach node where the LAST edge
        // used has 'color'
        vector<vector<int>> dist(n, vector<int>(2, -1));

        queue<pair<int, int>> q;

        // Start node can be considered as having either color.
        dist[0][0] = 0;
        dist[0][1] = 0;

        // 0 -> last edge was red
        // 1 -> last edge was blue
        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            int node = q.front().first;
            int lastColor = q.front().second;
            q.pop();

            for (auto edge : adj[node]) {
                int neigh = edge.first;
                int edgeColor = edge.second;

                // We need alternating colors
                if (edgeColor == lastColor)
                    continue;

                // If this state has not been visited
                if (dist[neigh][edgeColor] == -1) {
                    dist[neigh][edgeColor] =
                        dist[node][lastColor] + 1;

                    q.push({neigh, edgeColor});
                }
            }
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1 && dist[i][1] == -1) {
                ans[i] = -1;
            }
            else if (dist[i][0] == -1) {
                ans[i] = dist[i][1];
            }
            else if (dist[i][1] == -1) {
                ans[i] = dist[i][0];
            }
            else {
                ans[i] = min(dist[i][0], dist[i][1]);
            }
        }

        return ans;
    }
};