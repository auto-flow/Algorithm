from collections import Counter


class Solution:
    def countOfAtoms(self, formula: str):
        N = len(formula)
        stack = [Counter()]
        i = 0
        while i < N:
            if formula[i] == "(":
                stack.append(Counter())
                i += 1
            elif formula[i] == ")":
                top = stack.pop()
                i += 1
                i_start = i
                while i < N and formula[i].isdigit():
                    i += 1
                multi = int(formula[i_start:i] or 1)
                for name, cnt in top.items():
                    stack[-1][name] += cnt * multi
            else:
                i_start = i
                i += 1
                while i < N and formula[i].islower():
                    i += 1
                name = formula[i_start:i]
                i_start = i
                while i < N and formula[i].isdigit():
                    i += 1
                multi = int(formula[i_start:i] or 1)
                stack[-1][name] += multi
        return "".join(name + (str(stack[-1][name]) if stack[-1][name] > 1 else '')
                       for name in sorted(stack[-1]))


print(Solution().countOfAtoms("Mg(OH)2"))
