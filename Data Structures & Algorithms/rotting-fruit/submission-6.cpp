class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int minutes = 0;

        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // Find all rotten oranges and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        while (!q.empty() && fresh > 0) {
            minutes++;
            int size = q.size();

            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if ((unsigned)nx < m &&
                        (unsigned)ny < n &&
                        grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }

        }

        return fresh == 0 ? minutes : -1;
    }
};