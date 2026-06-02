class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        
        dp = [0] * (n+2)

        for i in reversed(range(n)):
            dp[i] = cost[i] + min(dp[i+1],dp[i+2])

        return min(dp[0],dp[1])