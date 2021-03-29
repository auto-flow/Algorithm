
[62. 不同路径](https://leetcode-cn.com/problems/unique-paths/)

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp=[[0]*(n+1) for _ in range(m+1)]
        dp[1][1]=1
        for i in range(1, m+1):
            for j in range(1, n+1):
                if i==1 and j==1:
                    continue
                dp[i][j]=dp[i-1][j]+dp[i][j-1]
        return dp[m][n]
```

[63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)

```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m=len(obstacleGrid)
        n=len(obstacleGrid[0])
        dp=[[0]*(n+1) for _ in range(m+1)]
        # dp[1][1]=1
        for i in range(1, m+1):
            for j in range(1, n+1):
                if obstacleGrid[i-1][j-1]==1:
                    continue
                if i==1 and j==1:
                    dp[1][1]=1
                    continue
                dp[i][j]=dp[i-1][j]+dp[i][j-1]

        return dp[m][n]
```
