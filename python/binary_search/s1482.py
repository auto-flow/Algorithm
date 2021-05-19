from typing import List


def get_m_pred(bloomDay, k, day_pred):
    cur_k = 0  # 相邻的k朵花
    cur_m = 0  # 累计摘了m束花
    for day in bloomDay:
        if day < day_pred:
            cur_k += 1
            if cur_k == k:
                cur_k = 0
                cur_m += 1
        else:
            cur_k = 0
    return cur_m


class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:

        if m * k > len(bloomDay):
            return -1
        # 最小天数
        l = min(bloomDay)
        # 最大天数
        r = max(bloomDay)
        while l < r:
            # 二分得到的天数
            day_pred = (l + r) // 2
            # 当前天数下能摘到 m_pred 束花
            m_pred = get_m_pred(bloomDay, k, day_pred)
            if m_pred > m:
                r = day_pred
            elif m_pred == m:
                r = day_pred
            elif m_pred < m:
                l = day_pred + 1
        return l
