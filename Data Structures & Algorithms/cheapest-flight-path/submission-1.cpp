class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> next_cost = cost;

            for (const auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if (cost[from] == INT_MAX) continue;

                next_cost[to] = min(next_cost[to],cost[from]+price);
            }
            cost = move(next_cost);
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
