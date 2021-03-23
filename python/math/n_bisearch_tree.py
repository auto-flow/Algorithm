def C(a, b):
    ans = 1
    for _ in range(b):
        ans *= a
        a -= 1
    while b >= 1:
        ans //= b
        b -= 1
    return ans

def catalan(n):
    return C(2*n, n) // (n + 1)


print(catalan(3))
