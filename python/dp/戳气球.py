from typing import List


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        points = [1] * (n + 2)
        for i in range(n):
            points[i + 1] = nums[i]
        dp = [[0] * (n + 2) for _ in range(n + 2)]
        for itv in range(2, n+2):  # [2,n+1]
            for i in range(0, n - itv + 2):
                j = i + itv
                for k in range(i + 1, j):
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i][k] + dp[k][j] + points[i] * points[j] * points[k],
                    )
                print(i, j, dp[i][j])
        print(dp)
        return dp[0][n + 1]


ans = Solution().maxCoins([3, 1, 5, 8])
print(ans)
