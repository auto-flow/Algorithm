from typing import List


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:

        counts = [0] * len(nums)
        index = [i for i in range(len(nums))]

        def merge_sort(l, r):
            if l >= r:
                return
            mid = (r + l) // 2
            merge_sort(l, mid)
            merge_sort(mid + 1, r)
            # 统计
            b = mid + 1
            for a in range(l, mid + 1):
                while b <= r and nums[index[b]] < nums[index[a]]:
                    b += 1
                counts[index[a]] += b - mid - 1
            # 归并
            a = l
            b = mid + 1
            merged = []
            while a <= mid and b <= r:
                if nums[index[a]] <= nums[index[b]]:
                    merged.append(index[a])
                    a += 1
                else:
                    merged.append(index[b])
                    b += 1
            while a <= mid:
                merged.append(index[a])
                a += 1
            while b <= r:
                merged.append(index[b])
                b += 1
            index[l:r + 1] = merged

        merge_sort(0, len(nums) - 1)
        # print(index)
        return counts


nums = [5, 2, 6, 1]
ans = Solution().countSmaller(nums)
print(nums)
print(ans)
