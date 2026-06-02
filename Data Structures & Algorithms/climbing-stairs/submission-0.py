class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n

        prev2, prev1 = 1, 2 # w.r.t n=3

        for _ in range(3, n + 1):
            prev2, prev1 = prev1, prev1 + prev2

        return prev1

        # time: O(n)
        # space: O(1)