class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;
        vector<vector<int>> graph(n);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        unordered_set<int> visited;
        queue<pair<int, int>> q;

        q.emplace(0, -1);  // arbitary starting
        visited.insert(0);

        while (!q.empty()) {
            auto [cur, parent] = q.front();
            q.pop();

            for (int nei : graph[cur]) {
                if (nei == parent) continue;
                if (visited.count(nei)) return false;

                visited.insert(nei);
                q.emplace(nei, cur);
            }
        }

        return visited.size() == n;
    }
};
