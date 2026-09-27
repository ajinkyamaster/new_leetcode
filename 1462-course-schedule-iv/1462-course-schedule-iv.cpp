class Solution {
public:
    void bfs(int src, vector<vector<int>>& adj,
             vector<int>& vis, vector<vector<bool>> &isPossible) {

        queue<int> q;
        q.push(src);
        vis[src] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : adj[node]) {

                if (!vis[neigh]) {
                    
                    vis[neigh] = 1;

                    isPossible[src][neigh] = true;

                    q.push(neigh);
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<bool> ans;

        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        vector<vector<bool>> isPossible(n, vector<bool>(n, false));

        for(int i=0;i<n;i++){
            vector<int> vis(n, 0);
            bfs(i, adj, vis, isPossible);
        }

        for(auto q: queries){
            ans.push_back(isPossible[q[0]][q[1]]);
        }

        return ans;

    }
};