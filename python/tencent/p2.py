T = int(input())
while T:
    T -= 1
    l, r, k = [int(x) for x in input().split()]
    ans = 0
    for i in range(l, r +1):
        ans += ((i + 10 ** (-k)) ** (1 / 3) - (i ** (1 / 3)))
    print('%.6g' % ans)
