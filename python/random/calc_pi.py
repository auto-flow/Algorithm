from math import sqrt
from random import random

def sample_pi(max_cnt=100000):
    acc_cnt=0
    for i in  range(max_cnt):
        x=random()
        y=random()
        if sqrt(x**2+y**2)<1:
            acc_cnt+=1
    print("pi =",acc_cnt/max_cnt*4)

sample_pi()
