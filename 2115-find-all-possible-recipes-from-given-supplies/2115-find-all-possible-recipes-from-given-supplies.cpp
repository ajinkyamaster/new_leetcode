class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;

        // Build graph
        for (int i = 0; i < recipes.size(); i++) {

            indegree[recipes[i]] = ingredients[i].size();

            for (auto &ingredient : ingredients[i]) {
                adj[ingredient].push_back(recipes[i]);
            }
        }

        // Initially available supplies
        queue<string> q;

        for (auto &supply : supplies) {
            q.push(supply);
        }

        vector<string> ans;   // <-- missing declaration

        // Topological sort
        while (!q.empty()) {

            string item = q.front();
            q.pop();

            for (auto &recipe : adj[item]) {

                indegree[recipe]--;

                if (indegree[recipe] == 0) {
                    ans.push_back(recipe);
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};