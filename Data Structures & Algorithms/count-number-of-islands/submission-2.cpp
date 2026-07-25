class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '#';
                    q.emplace(i, j);

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (auto [dx, dy] : dirs) {
                            int nx = x + dx;
                            int ny = y + dy;

                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                                grid[nx][ny] = '#';
                                q.emplace(nx, ny);
                            }
                        }
                    }
                    islands++;
                }
            }
        }
        return islands;
    }
};
