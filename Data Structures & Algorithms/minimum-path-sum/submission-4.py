class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)  # rows
        n = len(grid[0])  # cols

        dp = [[-1] * n for _ in range(m)]
        dirs = [
            (1, 0),  # down
            (0, 1),  # right
        ]

        def dfs(r: int, c: int) -> int:

            if r >= m or c >= n:
                return float("inf")  # type: ignore
    
            if dp[r][c] != -1:
                return dp[r][c]

            if r == m - 1 and c == n - 1:
                return grid[r][c]

            dp[r][c] = grid[r][c] + min(dfs(r + dr, c + dc) for dr, dc in dirs)

            return dp[r][c]

        return dfs(
            r=0,
            c=0,
        )
