from random import randint

N = 100
K = 10
res = [0] * K
i = K
for j in range(N):
    ix = randint(0, i - 1)
    if ix < K:
        res[ix] = j
    i += 1
print(res)
