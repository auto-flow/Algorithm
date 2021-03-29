import numpy as np


class Tanh:
    @staticmethod
    def forward(x):
        return (np.exp(x) - np.exp(-x)) / (np.exp(x) + np.exp(-x))

    @staticmethod
    def backward(x):
        return 1 - np.square(Tanh.forward(x))


def concat_1(X):
    return np.hstack([X, np.ones([X.shape[0], 1])])


class MLP():
    def __init__(self, n_input=1, n_hidden=3, n_output=1, lr=0.01):
        self.lr = lr
        self.n_output = n_output
        self.n_hidden = n_hidden
        self.n_input = n_input
        self.W1 = np.random.randn(n_input + 1, n_hidden)
        self.W2 = np.random.randn(n_hidden + 1, n_output)

    def epoch(self, X, y):
        X = concat_1(X)
        A = X @ self.W1  # N x n_hidden
        Z = Tanh.forward(A)
        Z = concat_1(Z)  # N x n_hidden+1
        O = Z @ self.W2  # N x n_output
        E = 0.5 * np.square((y - O))
        E = np.sum(E)
        dW2 = Z.T @ (y - O)
        # dW1=


if __name__ == '__main__':
    X = np.random.rand(100, 1)
    Y = 4 * X + 3 + np.random.rand(100, 1) * 0.1
    MLP().epoch(X, Y)
