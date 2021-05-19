class Solution:
    def mySqrt(self, x: int) -> int:
        eps = 1e-5
        l = 0
        r = x
        map = {0: 0, 1: 1}
        if x in map:
            return map[x]
        while True:
            mid = (l + r) / 2
            x_pred = mid ** 2
            if abs(x_pred - x) < eps:
                return int(mid)
            if x_pred < x:
                l = mid
            else:
                r = mid
