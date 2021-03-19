from math import inf

n, m, s, t = [int(x) for x in input().split()]
g = [[] for _ in range(n + 1)]
vis = [0 for _ in range(n + 1)]
for i in range(m):
    u, v, w = [int(x) for x in input().split()]
    g[u].append([v, w])
    g[v].append([u, w])
ans = inf


def dfs(s, t, weight):
    global ans
    if s == t:
        ans = min(weight, ans)
    vis[s] = 1
    for to, w in g[s]:
        if vis[to] == 0:
            dfs(to, t, max(weight, w))
    vis[s] = 0


dfs(s, t, -inf)
print(ans)
