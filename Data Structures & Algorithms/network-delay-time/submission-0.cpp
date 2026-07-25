class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // build graph
        vector<vector<pair<int, int>>> graph(n + 1);

        for (const vector<int>& time : times) {
            int src = time[0];
            int dest = time[1];
            int weight = time[2];

            graph[src].emplace_back(dest, weight);
        }

        // arr[node] = delay;
        vector<int> delay(n + 1, INT_MAX);
        // [delay,node]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        delay[k] = 0;
        pq.emplace(0,k);

        while(!pq.empty()){
            auto [cur_delay,node] = pq.top();
            pq.pop();

            if(cur_delay > delay[node]) continue;

            for(auto  [nei,weight]: graph[node]){
                if(cur_delay + weight < delay[nei]){
                    delay[nei] = cur_delay + weight;
                    pq.emplace(delay[nei],nei);
                }
            }
        }

        int res = 0;
        for(int i =1; i < delay.size(); i ++){
            int d = delay[i];
            if(d == INT_MAX) return -1;
            res = max(res,d);
        }

        return res;
    }
};
