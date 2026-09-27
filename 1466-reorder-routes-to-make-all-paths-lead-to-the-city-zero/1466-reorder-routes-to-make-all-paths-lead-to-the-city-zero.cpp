class Solution {
public:
     int dfs(int node,  vector<vector<int>> &adjReal,  vector<vector<int>> &adjfake, int reversed,vector<int> &vis){
        vis[node] = 1;

        for(auto neigh: adjReal[node]){
            if(!vis[neigh]){
                reversed = dfs(neigh, adjReal, adjfake, reversed+1, vis);
            }
        }

        for(auto neigh: adjfake[node]){
            if(!vis[neigh]){
                reversed = dfs(neigh, adjReal, adjfake, reversed, vis);
            }
        }

        return reversed;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjReal(n);
        vector<vector<int>> adjfake(n);

        vector<int> vis(n, 0);


        for(auto it: connections){
            adjReal[it[0]].push_back(it[1]);
            adjfake[it[1]].push_back(it[0]);
        }


        return dfs(0, adjReal, adjfake, 0, vis);




    }
};