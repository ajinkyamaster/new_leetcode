class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        if (health - grid[n-1][m-1] < 1) return false;

        queue<tuple<int,int,int>> q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        q.push({n-1, m-1, health - grid[n-1][m-1]});
        vis[n-1][m-1] = health - grid[n-1][m-1];

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [i, j, h] = q.front();
            q.pop();

            if (i == 0 && j == 0) return true;

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x < 0 || y < 0 || x >= n || y >= m)
                    continue;

                int nh = h - grid[x][y];

                if (nh >= 1 && nh > vis[x][y]) {
                    vis[x][y] = nh;
                    q.push({x, y, nh});
                }
            }
        }

        return false;
    }
};