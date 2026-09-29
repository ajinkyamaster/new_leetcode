class Solution {
public:

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        vector<vector<bool>> isConnected(n, vector<bool>(n, false));


        for(auto path: roads){
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
            degree[path[0]]++;
            degree[path[1]]++;

            isConnected[path[0]][path[1]] = true;
            isConnected[path[1]][path[0]] = true;

        }

        int maxNetworkRank = -1;
        int rank = 0;

       for(int i=0;i<n;i++){
            rank = 0;
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]){
                    rank = max(degree[i]+degree[j]-1, rank);
                }
                else{
                    rank = max(degree[i]+degree[j], rank);
                }
            }
            maxNetworkRank = max(maxNetworkRank, rank);
       }

        return maxNetworkRank;

    }
};