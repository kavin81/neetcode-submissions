class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[-1] * n for _ in range(m)]
        dirs = [
            (0,1), # right
            (1,0)  # down
        ]

        def dfs(r, c):
            # out-of-bound check
            if r >= m or c >= n:
                return 0
            # end-of-grid check
            if r == m - 1 and c == n - 1:
                return 1
            # memoize
            if dp[r][c] == -1:
                dp[r][c] = sum(dfs(r+dr,c+dc) for dr,dc in dirs)
            
            return dp[r][c]

        return dfs(
            r=0,
            c=0,
        )
