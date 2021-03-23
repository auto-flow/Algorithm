class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        N = len(prices)
        K = 2
        dp = [[[0] * 2 for _ in range(K + 1)] for _ in range(N + 1)]
        # $1 天数 $2 最大交易数 $3 {0: 不持有, 1: 持有}
        # dp[0][..][1]=-inf
        for k in range(K + 1): # 开始时不能持有股票
            dp[0][k][1] = -inf
        # dp[..][0][1]=-inf
        for i in range(N + 1):   
            dp[i][0][1] = -inf
        for i in range(1, N + 1):
            for k in range(2, 0, -1):
                # 卖
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i - 1])
                # 买
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i - 1])
        return dp[N][2][0]
