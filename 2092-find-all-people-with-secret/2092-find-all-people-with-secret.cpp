class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<vector<pair<int, int>>> adj(n);

        for (auto &m : meetings) {
            int x = m[0];
            int y = m[1];
            int time = m[2];

            adj[x].push_back({y, time});
            adj[y].push_back({x, time});
        }

        // Person 0 shares the secret with firstPerson at time 0
        adj[0].push_back({firstPerson, 0});
        adj[firstPerson].push_back({0, 0});

        // dist[i] = earliest time at which i knows the secret
        vector<int> dist(n, INT_MAX);

        // {knowingTime, person}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[0] = 0;
        dist[firstPerson] = 0;

        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()) {

            auto [knowingTime, person] = pq.top();
            pq.pop();

            // Ignore an outdated entry
            if (knowingTime != dist[person])
                continue;

            for (auto &[neigh, meetingTime] : adj[person]) {

                // Person can share only if they already know
                // the secret when the meeting happens
                if (meetingTime < knowingTime)
                    continue;

                // We found an earlier time for neigh
                if (meetingTime < dist[neigh]) {
                    dist[neigh] = meetingTime;
                    pq.push({meetingTime, neigh});
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (dist[i] != INT_MAX)
                ans.push_back(i);
        }

        return ans;
    }
};