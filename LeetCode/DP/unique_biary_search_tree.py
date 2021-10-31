# https://leetcode.com/problems/unique-binary-search-trees/


class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0 for _ in range(n + 1)]
        dp[0] = 1
        dp[1] = 1

        for i in range(2, n + 1):
            dp[i] = 2 * dp[i - 1] + sum(
                [dp[x + 1] * dp[i - 2 - x] for x in range(i - 2)]
            )
        return dp[n]


s = Solution()
assert s.numTrees(3) == 5
