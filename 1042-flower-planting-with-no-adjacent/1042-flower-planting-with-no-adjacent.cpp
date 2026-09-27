class Solution {
public:
    void bfs(int garden, vector<vector<int>>& adj,
             vector<int>& color, vector<int>& vis) {

        queue<int> q;
        q.push(garden);
        vis[garden] = 1;

        while (!q.empty()) {
            int garden = q.front();
            q.pop();

            // Find colors used by already-colored neighbors
            bool used[5] = {false};

            for (int neigh : adj[garden]) {
                if (color[neigh - 1] != 0) {
                    used[color[neigh - 1]] = true;
                }
            }

            // Give current garden the smallest available color
            for (int c = 1; c <= 4; c++) {
                if (!used[c]) {
                    color[garden - 1] = c;
                    break;
                }
            }

            // Visit unvisited neighbors
            for (int neigh : adj[garden]) {
                if (!vis[neigh]) {
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> color(n, 0);
        vector<int> vis(n + 1, 0);

        vector<vector<int>> adj(n + 1);

        for (auto& it : paths) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                bfs(i, adj, color, vis);
            }
        }

        return color;
    }
};