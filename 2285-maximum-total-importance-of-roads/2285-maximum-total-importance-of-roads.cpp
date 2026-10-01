class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);

        for (auto road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        vector<pair<int,int>> cities;

        for (int i = 0; i < n; i++) {
            cities.push_back({degree[i], i});
        }

        sort(cities.rbegin(), cities.rend());

        vector<int> value(n);

        int weight = n;

        for (auto city : cities) {
            value[city.second] = weight;
            weight--;
        }

        long long ans = 0;

        for (auto road : roads) {
            ans += value[road[0]] + value[road[1]];
        }

        return ans;
    }
};