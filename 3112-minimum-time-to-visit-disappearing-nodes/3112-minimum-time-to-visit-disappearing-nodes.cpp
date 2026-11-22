class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        
        vector<vector<pair<int, int>>> adj(n);

        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> min_time(n, 1e9);
        vector<int> vis(n, 0);

        pq.push({0, 0});
        min_time[0] = 0;

        while(!pq.empty()){
            auto [parent_time_req, node] = pq.top();
            pq.pop();
            vis[node] = 1;
            if (parent_time_req > min_time[node]) continue;

            for(auto it: adj[node]){
                int neigh = it.first;
                int time = it.second;
                
                if(!vis[neigh] && parent_time_req + time < min_time[neigh] && parent_time_req +time < disappear[neigh]){
                    min_time[neigh] = parent_time_req + time;

                    pq.push({min_time[neigh], neigh});
                }

            }

        }

        for(int i=0;i<n;i++){
            if(min_time[i] == 1e9){
                min_time[i] = -1;
            }
           
        }

        return min_time;
    }
};