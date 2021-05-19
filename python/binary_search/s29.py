def mul(a: int, b: int):
    ans = 0
    while b:
        if b & 1:
            ans += a
        b >>= 1
        a += a
    return ans


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        x, y = dividend, divisor
        is_neg = x * y < 0
        if x < 0:
            x = 0 - x
        if y < 0:
            y = 0 - y
        l, r = 0, x
        while l < r:
            # mid = (l + r) >> 1
            # x_pred = mul(mid, y)
            # if x_pred == x:
            #     r = mid
            # elif x_pred < x:
            #     l = mid + 1
            # elif x_pred > x:
            #     r = mid
            mid = (l + r + 1) >> 1
            x_pred = mul(mid, y)
            if x_pred <= x:
                l = mid
            else:
                r = mid - 1
        # l-=1
        if is_neg:
            l = 0 - l
        ans = l
        MAX_VALUE = 2 ** 31 - 1
        MIN_VALUE = -2 ** 31
        if ans > MAX_VALUE or ans < MIN_VALUE:
            return MAX_VALUE
        return ans


print(Solution().divide(10, 3))
