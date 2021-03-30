#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author  : qichun tang
# @Date    : 2021-03-30
# @Contact    : qichun.tang@bupt.edu.cn
s1 = ['欢迎', '您', '面试', '.']
s2 = ['欢迎', '你', '来', '面试', '.']
l1 = len(s1)
l2 = len(s2)
dp = [[0] * (l2 + 1) for _ in range(l1 + 1)]
for i in range(1, l1 + 1):
    for j in range(1, l2 + 1):
        if s1[i - 1] == s2[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
i = l1
j = l2
LCS = []
while i > 0 and j > 0:
    if s1[i - 1] == s2[j - 1]:
        LCS.append(s1[i - 1])
        i -= 1
        j -= 1
    elif dp[i - 1][j] > dp[i][j - 1]:
        i -= 1
    else:
        j -= 1
LCS = LCS[::-1]

l3 = len(LCS)
ans1 = []
ans2 = []
i = 0
j = 0
for k in range(l3):
    while i < l1 and s1[i] != LCS[k]:
        i += 1
        ans1.append(str(i))
        ans2.append(' ')
    while j < l2 and s2[j] != LCS[k]:
        j += 1
        ans2.append(str(j))
        ans1.append(' ')
    i += 1
    j += 1
    ans1.append(str(i))
    ans2.append(str(j))
print(ans1)
print(ans2)
