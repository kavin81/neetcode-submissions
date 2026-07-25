class Solution {
public:
    enum Orange {
        EMPTY = 0,
        FRESH = 1,
        ROTTEN = 2
    };

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
                if (grid[i][j] == ROTTEN) {
                    q.push({i, j});
                } 
                else if (grid[i][j] == FRESH) {
                    fresh++;
                }
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

                    if (nx >= 0 && nx < m &&
                        ny >= 0 && ny < n &&
                        grid[nx][ny] == FRESH) {

                        grid[nx][ny] = ROTTEN;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};