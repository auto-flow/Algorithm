from typing import List


class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        result = [kill]
        parent = dict(zip(pid, ppid))
        parent[0] = 0
        for i in parent.keys():
            x = self.find(i, parent, kill)
            if x == kill:
                result.append(i)
        return result

    def find(self, x, parent, kill):
        # 在kill处早停
        if parent[x] == kill:
            return kill
        # 路径压缩
        p = parent[x]
        if parent[x] != x:
            p = self.find(p, parent, kill)
        parent[x] = p
        return p


res = Solution().killProcess([1, 3, 10, 5], [3, 0, 5, 3], 5)
print(res)
