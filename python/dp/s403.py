from typing import List
from collections import defaultdict

class Solution:
    def canCross(self, stones: List[int]) -> bool:
        end = stones[-1]
        visited = defaultdict(bool)  # 记忆化+dfs
        stones_set = set(stones)  # 为了查找更快

        def dfs(start: int, pre_step: int) -> bool:
            if start == end:
                return True
            if (start, pre_step) in visited:
                return visited[(start, pre_step)]
            for cur_step in (pre_step - 1, pre_step, pre_step + 1):
                if cur_step <= 0:  # 如果向左了，或者原地了
                    continue
                nxt_start = start + cur_step  # 下一步的开始（起跳点）
                if nxt_start in stones_set and dfs(nxt_start, cur_step) == True:  # 下一步踩在石头上，且后面能到终点
                    visited[(start, pre_step)] = True
                    return True
            visited[(start, pre_step)] = False
            return False

        return dfs(stones[0], 0)


ans = Solution().canCross([0, 1, 3, 5, 6, 8, 12, 17])
print(ans)
