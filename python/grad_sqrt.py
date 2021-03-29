C = 9


def get_dx(x):
    return 4 * (x ** 3) - 4 * x * C


def get_dx2(x):
    return x ** 2 - C


y = 1
lr = 0.01
for i in range(10000):
    y -= lr * get_dx2(y)
print(y)
