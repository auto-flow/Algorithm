from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        # 棋盘
        board = [["."] * n for _ in range(n)]
        # 对角线1 【用于记录 对角线1 是否有棋子】
        dj1 = [0] * (2 * n)
        # 对角线2 【用于记录 对角线2 是否有棋子】
        dj2 = [0] * (2 * n)
        # 列 【用于记录 列 是否有棋子】
        col = [0] * n
        ans = []

        # i 表示行
        def dfs(i):
            # 所有的行都走过了，【解集更新】
            if i == n:
                ans.append(["".join(line) for line in board])
            # 对所有列进行遍历，找到合适的列j，并占用位置，再转移到下一个状态 i+1行 中
            for j in range(n):  # j 表示列。
                # 计算在两个对角线上的坐标
                ix1 = j + i
                ix2 = j - i + n
                # 如果当前坐标 (i, j) 不合适，如在【列】或【对角线】上与其他棋子重合，continue
                if col[j] == 1 or dj1[ix1] == 1 or dj2[ix2] == 1:
                    continue
                # 占用这个位置
                col[j] = 1
                dj1[ix1] = 1
                dj2[ix2] = 1
                board[j][i] = 'Q'
                # 在放置 (i, j) 棋子的状态下，转移到 i+i 行
                dfs(i + 1)
                # 释放这个位置
                board[j][i] = '.'
                col[j] = 0
                dj1[ix1] = 0
                dj2[ix2] = 0

        dfs(0)
        return ans

print(Solution().solveNQueens(8))