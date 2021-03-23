from random import shuffle

import numpy as np
from sklearn.metrics import roc_auc_score

scores = []
for i in range(1000):
    y_true = [1] * 100 + [0] * 900
    shuffle(y_true)
    y_pred = np.random.rand(1000)
    score = roc_auc_score(y_true, y_pred)
    scores.append(score)
print(np.mean(scores))
print(np.mean(scores))

