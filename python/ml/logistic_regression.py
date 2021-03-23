import numpy as np
import pylab as plt
from sklearn.datasets import load_iris
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import StandardScaler


class LR:
    def __init__(self, lr=0.1, max_iter=1000, eps=1e-5):
        self.eps = eps
        self.max_iter = max_iter
        self.lr = lr

    def predict_proba(self, X):
        return 1 / (1 + np.exp(-X @ self.w))

    def fit(self, X: np.ndarray, y: np.ndarray):
        n, m = X.shape
        X = np.hstack([X, np.ones([n, 1])])
        m += 1
        self.w = np.zeros([m])
        pre_loss = 0
        for i in range(self.max_iter):
            y_hat = self.predict_proba(X)
            # 交叉熵
            loss = -(y @ np.log(y_hat) + (1 - y) @ np.log(1 - y_hat)) / n
            if abs(loss - pre_loss) < self.eps:
                print('误差不再减少')
                break
            pre_loss = loss
            print(loss)
            # 计算梯度
            dw = (y - y_hat) @ X
            dw /= n
            # 梯度下降
            self.w += dw * self.lr
            print(self.w)


X, y = load_iris(True)
X = X[:, [0, 1]]
X = StandardScaler().fit_transform(X)
y = (y >= 2).astype(int)

my_lr = LR()
my_lr.fit(X, y)

lr = LogisticRegression()
lr.fit(X, y)
print(lr.coef_)
print(lr.intercept_)
w1, w2 = lr.coef_[0]
b = lr.intercept_[0]
plt.scatter(X[:, 0][y == 0], X[:, 1][y == 0])
plt.scatter(X[:, 0][y == 1], X[:, 1][y == 1])
ds = np.array([
    [0, -b / w2],
    [-b / w1, 0],
])
plt.plot(ds[:, 0], ds[:, 1])
# plt.show()
