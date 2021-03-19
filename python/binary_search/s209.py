import bisect
from typing import List

nums=[1,2,3,3,3,4]
print(bisect.bisect_left(nums,3))
print(bisect.bisect_right(nums,3))

class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        if not nums:
            return 0

        n = len(nums)
        ans = n + 1
        sums = [0]
        for i in range(n):
            sums.append(sums[-1] + nums[i])

        for i in range(1, n + 1):
            target = s + sums[i - 1]
            bound = bisect.bisect_left(sums, target)
            if bound != len(sums):
                ans = min(ans, bound - (i - 1))

        return 0 if ans == n + 1 else ans


ans = Solution().minSubArrayLen(7, [2, 3, 1, 2, 4, 3])
print(ans)
