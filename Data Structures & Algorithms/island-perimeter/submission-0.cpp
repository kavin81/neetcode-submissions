class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int m = grid.size();
        int n = grid[0].size();
        int p = 0;

        /*
            0 = water
            1 = land
            2 = visited
        */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 2;  // visited

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (auto [dx, dy] : dirs) {
                            int nx = x + dx;
                            int ny = y + dy;

                            // OOB/water -> p++
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0) {
                                p++;
                            }
                            // unvisited land -> queue
                            else if (grid[nx][ny] == 1) {
                                grid[nx][ny] = 2;
                                q.push({nx, ny});
                            }
                        }
                    }
                    return p;
                }
            }
        }
        return 0;
    }
};