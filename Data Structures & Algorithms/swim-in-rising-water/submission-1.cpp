class Solution {
   public:
    using State = tuple<int, int, int>;  // {time,row,col}

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<State, vector<State>, greater<State>> min_heap;

        dist[0][0] = grid[0][0];
        min_heap.emplace(grid[0][0], 0, 0);

        while (!min_heap.empty()) {
            auto [t, r, c] = min_heap.top();
            min_heap.pop();

            // end of path
            if (r == n - 1 && c == n - 1) return t;

            // skip outdated path
            if (t > dist[r][c]) continue;

            // bfs on 4 dirs
            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                // catch OOB index
                if ((unsigned)nr >= n || (unsigned)nc >= n) continue;

                // is ith elevation > max([0,1,...n-1th elevation])
                int nt = max(t, grid[nr][nc]);

                if (nt < dist[nr][nc]) {
                    dist[nr][nc] = nt;
                    min_heap.emplace(nt, nr, nc);
                }
            }
        }
        return -1;
    }
};
