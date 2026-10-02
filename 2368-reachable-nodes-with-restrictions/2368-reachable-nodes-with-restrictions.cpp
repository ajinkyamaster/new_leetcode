class Solution {
public:
    int dfs(int src, vector<vector<int>> &adj, vector<int> &vis, vector<int> & restricted){
        vis[src] = 1;

        int count=1;

        for(auto neigh: adj[src]){
            if(vis[neigh]==0){
                count += dfs(neigh, adj, vis, restricted);
            }
        }

        return count;
    }   
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
         vector<vector<int>> adj(n);

        for (auto& e : edges) {
           adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);

        for(auto node: restricted){
            vis[node]=  -1;
        }

        int total = dfs(0, adj, vis, restricted);

        return total;
    }
};