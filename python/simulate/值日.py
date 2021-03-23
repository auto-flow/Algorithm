n, m = [int(x) for x in input().split()]
arr = [[]]
for i in range(n):
    arr.append([0] + [int(x) for x in input().split()])
i = 2
j = 1
tmp = 0
while m >= 0:
    tmp = arr[i][j]
    j = i
    i = tmp
    m -= 1
print(tmp)
