class Solution:
    def multiply(self, num1, num2):
        if num1 == '0' or num2 == '0':
            return '0'
        ans = '0'
        l1, l2 = len(num1), len(num2)
        for i in range(l2 - 1, -1, -1):
            add = 0
            y = int(num2[i])
            curr = ['0'] * (l2 - i - 1)
            for j in range(l1 - 1, -1, -1):
                product = int(num1) * y + add
                curr.append(str(product % 10))
                add = product // 10
            while add:
                curr.append(str(add % 10))
                add //= 10
            curr = "".join(curr[::-1])
            ans = self.addString(ans, curr)
        return ans

    def addString(self, s1, s2):
        i = len(s1) - 1
        j = len(s2) - 1
        carry = 0
        ans = []
        while i >= 0 or j >= 0 or carry:
            x = s1[i] if i >= 0 else 0
            y = s2[j] if j >= 0 else 0
            i -= 1
            j -= 1
            sum_ = x + y + carry
            carry = sum_ // 10
            ans.append(str(sum_ % 10))
        return "".join(ans)[::-1]
