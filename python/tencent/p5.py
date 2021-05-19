from collections import Counter

N = int(input())
DF = Counter()
counters = []
for _ in range(N):
    T = int(input())
    counter = Counter()
    for _ in range(T):
        word = input()
        counter[word] += 1
    for word in counter:
        DF[word] += 1
    counters.append(counter)
for i in range(N):
    counter = counters[i]
    imp = []
    for word in counter:
        imp.append(counter[word] / DF[word])
    print(f"{max(imp):.6f}")
