s = input()
a = input()
if not a:
    print(0)
ls, la = len(s), len(a)
alpha2ix = {}
for i, ch in enumerate(s):
    alpha2ix[ch] = i
indexes = [alpha2ix[ch] for ch in a]
# 记录有多少段连续上上的记录
n_sec = 0
pre = indexes[0]
for i in range(1, la):
    index = indexes[i]
    # 写成 < 导致只过了55%
    if index <= pre:
        n_sec += 1
    pre = index
print(n_sec * 26 + indexes[-1] + 1 - la)
