from collections import Counter


def get_sorted_counter(counter: dict):
    items = [(k, v) for k, v in counter.items()]
    items.sort(key=lambda x: (x[1], x[0]))
    return items


n, m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
ca = Counter(A)
cb = Counter(B)
# ma = get_sorted_counter(ca)[0][0]
# mb = get_sorted_counter(cb)[0][0]
ma = ca.most_common()[0][0]
mb = cb.most_common()[0][0]
print((mb - ma + m) % m)
