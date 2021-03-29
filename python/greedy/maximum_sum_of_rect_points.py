from math import inf
from pprint import pprint

import numpy as np


def get_random_data(M=10, N=10):
    return np.random.randint(0, 100, [M, N]).tolist()


def brute_force(mat):
    '''
    时间复杂度 N^3
    '''
    M = len(mat)
    N = len(mat[0])
    # N(N-1)/2 列， M 行
    N2 = N * (N - 1) // 2
    mat2 = [[0] * N2 for _ in range(M)]
    for i in range(M):
        q = 0
        for j in range(1, N):
            for k in range(j):
                mat2[i][q] = mat[i][j] + mat[i][k]
                q += 1
    ans = -inf
    for j in range(N2):
        max1 = -inf
        max2 = -inf
        for i in range(M):
            cur_num = mat2[i][j]
            if cur_num > max1:
                max2 = max1
                max1 = cur_num
            elif cur_num > max2:
                max2 = cur_num
        ans = max(ans, max1 + max2)
    return ans


def fix_maximum_method(mat):
    '''
    时间复杂度 N^2
    '''
    M = len(mat)
    N = len(mat[0])
    # 1. 找到最大点
    max_v = -inf
    max_pt = ()
    for i in range(M):
        for j in range(N):
            if mat[i][j] > max_v:
                max_v = mat[i][j]
                max_pt = (i, j)
    # 2. 开始遍历
    fi, fj = max_pt
    ans = -inf
    for i in range(M):
        for j in range(N):
            if i == fi or j == fj:
                continue
            pts = [(i, j), (fi, fj), (i, fj), (fi, j)]
            cur_sum = 0
            for ci, cj in pts:
                cur_sum += mat[ci][cj]
            ans = max(ans, cur_sum)
    return ans

def run_test1():
    # 71+64+76+94
    data = [
        [23, 71, 64, 1],
        [12, 65, 57, 23],
        [36, 19, 28, 25],
        [81, 94, 76, 29],
    ]
    ans1 = brute_force(data)
    ans2 = fix_maximum_method(data)
    pprint(data)
    print(ans1)
    print(ans2)


if __name__ == '__main__':
    run_test1()