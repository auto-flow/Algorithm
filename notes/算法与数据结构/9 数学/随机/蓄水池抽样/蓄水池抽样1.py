from random import randint

N = 100
val = 0
i = 0
for j in range(N):
    if (randint(0, i) == 0):
        val = j
    i += 1
print(val)
