from typing import List


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:

        counts = [0] * len(nums)
        index = [i for i in range(len(nums))]

        def Merge_sort(low, high):
            if high - low < 2:
                return
            mid = (high + low) // 2
            Merge_sort(low, mid)
            Merge_sort(mid, high)
            tmp = mid
            pre = low
            res = []
            while low < mid or tmp < high:
                if low == mid or (tmp < high and nums[index[low]] <= nums[index[tmp]]):
                    res.append(index[tmp])
                    tmp += 1
                else:
                    res.append(index[low])
                    counts[index[low]] += high - tmp
                    low += 1

            index[pre:high] = res

        Merge_sort(0, len(nums))
        return counts


print(Solution().countSmaller([5, 2, 6, 1]))
