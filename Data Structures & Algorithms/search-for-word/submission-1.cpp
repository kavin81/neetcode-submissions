class Solution {
   public:
    int ROWS, COLS;
    vector<vector<int>> dirs =  {{0, 1}, {-1, 0}, {0, -1}, {1, 0}}; ;
    vector<vector<bool>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));


        for (int r = 0; r < ROWS; r++) 
            for (int c = 0; c < COLS; c++) 
                if(dfs(board,word,r,c,0))
                    return true;


        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c,int i) {
        if (i == word.length()) return true;

        if ((unsigned)r >= ROWS || (unsigned)c >= COLS || board[r][c] != word[i] || visited[r][c]) {
            return false;
        }
        visited[r][c] = true;

        for (auto& dir : dirs) {
            int dr = dir[0];
            int dc = dir[1];

            if (dfs(board, word, r + dr, c + dc, i + 1)) {
                return true;
            }
        }

        visited[r][c] = false;
        return false;
    }
};
