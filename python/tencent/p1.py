# from pprint import pprint

m, n = [int(x) for x in input().split()]
matrix = []
for _ in range(m):
    matrix.append([int(x) for x in input().split()])
min_ = [[1] * (n + 1) for _ in range(m + 1)]
max_ = [[1] * (n + 1) for _ in range(m + 1)]
min_[1][1] = max_[1][1] = matrix[0][0]
for i in range(2, m + 1):
    cur = matrix[i - 1][0]
    min_[i][1] = min(
        cur * min_[i - 1][1],
        cur * max_[i - 1][1],
    )
    max_[i][1] = max(
        cur * min_[i - 1][1],
        cur * max_[i - 1][1],
    )
for j in range(2, n + 1):
    cur = matrix[0][j - 1]
    min_[1][j] = min(
        cur * min_[1][j - 1],
        cur * max_[1][j - 1],
    )
    max_[1][j] = max(
        cur * min_[1][j - 1],
        cur * max_[1][j - 1],
    )
# pprint(min_,width=30)
# pprint(max_,width=30)
for i in range(2, m + 1):
    for j in range(2, n + 1):
        cur = matrix[i - 1][j - 1]
        min_[i][j] = min(
            cur * min_[i - 1][j],
            cur * min_[i][j - 1],
            cur * max_[i - 1][j],
            cur * max_[i][j - 1],
        )
        max_[i][j] = max(
            cur * min_[i - 1][j],
            cur * min_[i][j - 1],
            cur * max_[i - 1][j],
            cur * max_[i][j - 1],
        )
ans = max_[-1][-1]
print(-1 if ans < 0 else ans % int(1e9 + 7))
