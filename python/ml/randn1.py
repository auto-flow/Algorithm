import numpy as np
import pylab as plt

n = 12
N = 5000
x = np.zeros([N])
for j in range(N):
    a = np.random.rand(n)
    u = sum(a)
    x[j] = u - n * 0.5
plt.hist(x)
plt.show()
