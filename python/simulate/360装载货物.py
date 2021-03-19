from math import ceil

while (True):
    try:
        istr = input()
    except:
        break
    if not istr: break
    a, b, k, v = [int(x) for x in istr.split()]
    ans = 0
    # 一个箱子需要的隔板数
    kk = k - 1
    # 完整箱子
    wzxz = b // kk
    # 剩余隔板
    sygb = 0
    if b > kk:
        sygb = b % kk
    # 完整箱子的隔板用完可以把物品装完
    if wzxz * (k * v) >= a:  # 直接返回完整箱子肯定是多的，所以这么算
        print(ceil(a / (k * v)))
        continue
    # 完整箱子不能把物品装完，增加完整箱子的个数，并减去相应物品
    else:
        ans += wzxz
        a -= (wzxz * (k * v))
    # 如果有剩余隔板，也算作一个箱子
    if sygb > 0:
        ans += 1
        a -= (sygb + 1) * v
    # 剩余物品老老实实装箱
    ans += ceil(a / v)
    print(ans)
