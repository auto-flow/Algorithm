import numpy as np
import pylab as plt

N = 1000
x1 = np.random.rand(1, N)
x2 = np.random.rand(1, N)
y1 = np.sqrt(-2 * np.log(x1)) * np.cos(2 * np.pi * x2)
y2 = np.sqrt(-2 * np.log(x1)) * np.sin(2 * np.pi * x2)
y = np.hstack([y1, y2])
plt.hist(y)
plt.show()
