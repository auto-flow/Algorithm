class Solution:

    def __init__(self, w: List[int]):
        N = len(w)
        sum_ = sum(w)
        prob = [p / sum_ for p in w]
        alias = [0] * N
        alias_prob = [p * N for p in prob]
        small_q = []
        large_q = []
        for i, p in enumerate(alias_prob):
            if p < 1:
                small_q.append(i)
            else:
                large_q.append(i)
        while small_q and large_q:
            small = small_q.pop(0)
            large = large_q.pop(0)
            alias[small] = large
            alias_prob[large] -= (1 - alias_prob[small])
            if alias_prob[large] < 1:
                small_q.append(large)
            else:
                large_q.append(large)
        self.alias = alias
        self.N = N
        self.alias_prob = alias_prob

    def pickIndex(self) -> int:
        ix = random.randint(0, self.N - 1)
        p = random.random()
        if p < self.alias_prob[ix]:
            return ix
        else:
            return self.alias[ix]
