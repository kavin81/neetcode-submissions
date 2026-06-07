class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # type: bottom-up
        # time: O(coins*amount)
        # space: O(amount)
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0

        for amt in range(1,amount+1):  
            for coin in coins:
                if amt - coin >= 0:
                    dp[amt] = min(dp[amt],1+ dp[amt-coin])
        
        
        return dp[amount] if dp[amount] != amount + 1 else -1
