class Solution {
public:
    int shortestPath(vector<vector<int>> &adj, int n){
        int length =0;
        vector<int> dist(n, 1e9);
        queue<int> q;

        q.push(0);
        dist[0] = 0;
        while(!q.empty()){
            int node= q.front();
            q.pop();

            for(auto neigh: adj[node]){
                if(dist[node]+1<dist[neigh]){
                    dist[neigh] = dist[node]+1;
                    q.push(neigh);
                }
            }
        }

        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);

        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        vector<int> ans(queries.size());
        int k = 0;


        for(auto q: queries){
            adj[q[0]].push_back(q[1]);

            ans[k++] = shortestPath(adj, n);
        }

        return ans;
    }
};