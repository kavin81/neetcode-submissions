from enum import IntEnum


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid[0])
        m = len(obstacleGrid)

        dp = [[-1] * n for _ in range(m)]
        dirs = [
            (0, 1),  # right
            (1, 0),  # down
        ]

        def dfs(r: int, c: int) -> int: 
            # OOB
            if r >= m or c >= n:
                return 0

            # obstacle
            if obstacleGrid[r][c] == 1:
                return 0
                
            # end of grid
            if r == m -1 and c == n-1:
                return 1

            if dp[r][c] == -1:
                dp[r][c] = sum(dfs(r+dr,c+dc) for dr,dc in dirs)
            


            return dp[r][c]
            

        return dfs(
            r=0,
            c=0,
        )

