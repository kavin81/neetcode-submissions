class Solution:
    def rob(self, nums: List[int]) -> int:
        # bottom up

        
        n = len(nums)
        if n < 3:
            return max(nums)
        
        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = max(nums[0],nums[1])

        for i in range(2,n):
            dp[i] = max(dp[i-1],nums[i]+dp[i-2])
            
        return dp[-1]

        # time: O(n)
        # space: O(n) (can be reduced to O(1) but lazy to)