
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < n-1; i++){
            adj[i].push_back(i+1);
        }

        vector<int> dist(n);
        for(int i = 0; i < n; i++){
            dist[i] = i;
        }

        vector<int> ans;

        for(auto &q : queries){
            int u = q[0];
            int v = q[1];

            adj[u].push_back(v);

            queue<int> que;

            if(dist[u] + 1 < dist[v]){
                dist[v] = dist[u] + 1;
                que.push(v);
            }

            while(!que.empty()){
                int node = que.front();
                que.pop();

                for(auto neigh : adj[node]){
                    if(dist[node] + 1 < dist[neigh]){
                        dist[neigh] = dist[node] + 1;
                        que.push(neigh);
                    }
                }
            }

            ans.push_back(dist[n-1]);
        }

        return ans;
    }
};
