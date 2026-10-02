class Solution {
public:
    int dfs(int src, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;
        int size = 1;

        for (int neigh : adj[src]) {
            if (!vis[neigh]) {
                size += dfs(neigh, adj, vis);
            }
        }

        return size;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);

        long long ans = 0;
        long long remaining = n;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                long long componentSize = dfs(i, adj, vis);

                remaining -= componentSize;

                ans += componentSize * remaining;
            }
        }

        return ans;
    }
};