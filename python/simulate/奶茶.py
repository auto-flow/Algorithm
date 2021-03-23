from heapq import heapify
from math import ceil

n, m, C = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
A = [-ceil(a / C) for a in A]
heapify(A)
ans = 0
while A:
    for i in range(min(m, len(A))):
        A[i] += 1
    A = [a for a in A if a != 0]
    ans += 1
    heapify(A)
print(ans)
