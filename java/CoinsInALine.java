class Solution_Coins {
    /**
     * @param values: an array of integers
     * @return: a boolean which equals to true if the first player will win
     */
    public boolean firstWillWin(int[] values) {
        // write your code here
        int len = values.length;
        int[] sum = new int[len + 1];
        //int [][] dp = new int[len][len];
        int[] dp1 = new int[len];

        sum[0] = 0;
        for (int i = 1; i <= len; i++) {
            sum[i] = sum[i - 1] + values[i - 1];
        }

        // Init dp(i,0) = values[i]
        for (int i = 0; i < len; i++) {
            //dp[i][0] = values[i];
            dp1[i] = values[i];
        }

        int tmp = 0;
        for (int k = 1; k < len; k++) {
            tmp = dp1[len - k];
            for (int i = len - k - 1; i >= 0; i--) {
                // sum(i) = add from index 0 to i-1
                // sum(i,j) = sum(j+1) - sum(i)
                // sum(i+1,i+k) = sum(i+k+1) - sum(i+1)
                // sum(i,i+k-1) = sum(i+k) - sum(i)
                // dp[i][k] = Math.max(values[i] + (sum[i+k+1] - sum[i+1]) - dp[i+1][k-1], values[i+k] + (sum[i+k] - sum[i]) - dp[i][k-1]);
                int tmp1 = dp1[i];
                dp1[i] = Math.max(
                        values[i] + (sum[i + k + 1] - sum[i + 1]) - tmp,
                        values[i + k] + (sum[i + k] - sum[i]) - dp1[i]
                );
                tmp = tmp1;
            }
        }

        if (dp1[0] * 2 > sum[len]) {
            return true;
        } else {
            return false;
        }
    }
}


public class CoinsInALine {
}
