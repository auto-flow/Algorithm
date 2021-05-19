from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        minF = nums[0]
        maxF = nums[0]
        n = len(nums)
        ans = maxF
        for i in range(1, n):
            num = nums[i]
            cur_minF = min(minF * num, maxF * num, num)
            cur_maxF = max(minF * num, maxF * num, num)
            minF = cur_minF
            maxF = cur_maxF
            ans = max(ans, maxF)
        return ans
