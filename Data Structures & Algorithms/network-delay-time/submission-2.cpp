class Solution {
   public:
    using Edge = pair<int, int>;   // {neighbor, weight}
    using State = pair<int, int>;  // {distance, node}

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list.
        vector<vector<Edge>> graph(n + 1);

        for (const vector<int>& time : times) {
            const int src = time[0];
            const int dest = time[1];
            const int weight = time[2];

            graph[src].emplace_back(dest, weight);
        }

        vector<int> delay(n + 1, INT_MAX);
        priority_queue<State, vector<State>, greater<State>> pq;

        delay[k] = 0;
        pq.emplace(0, k);

        while (!pq.empty()) {
            auto [cur_delay, node] = pq.top();
            pq.pop();

            // Skip stale heap entries.
            if (cur_delay > delay[node]) continue;

            // Relax all outgoing edges.
            for (const auto& [nei, weight] : graph[node]) {
                if (cur_delay + weight < delay[nei]) {
                    delay[nei] = cur_delay + weight;
                    pq.emplace(delay[nei], nei);
                }
            }
        }

        // Maximum shortest-path distance.
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (delay[i] == INT_MAX) return -1;
            res = max(res, delay[i]);
        }

        return res;
    }
};