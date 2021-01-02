import numpy as np
from random import uniform,randint

def func(x):
    a = np.random.normal(loc=0.0, scale=1.0, size=None)
    a = round(a,2)
    y = 6 * x + 10 
    return y

with open("Pytorch/datasets/p5_data.txt","w") as f:
    # 随机生成200 条数据
    for i in range(600):
        # 生生 -60 ~ 60 之间的浮点数
        x = randint(-1000,1000)
        y = func(x)
        f.write("{},{}\n".format(float(x),float(y)))