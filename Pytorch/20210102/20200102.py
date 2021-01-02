import torch
import numpy as np
import pandas as pd

# 实现linear 
# loss = (WX + b - y)^2
# w' = w - lr * △loss/△w 

# 计算错误率
# y = wx + b
def compute_error_for_line_given_points(b,w,points):
    totalError = 0
    for i in range(0,len(points)):
        x = points[i,0]
        y = points[i,1]
        totalError += (y-(w*x+b))**2

    return totalError / float(len(points))

# 计算梯度信息
def step_gradient(b_current,w_current,points,learningRate):
    b_gradient = 0
    w_gradient = 0
    N = float(len(points))
    for i in range(0,len(points)):
        x = points[i,0]
        y = points[i,1]
        # ▽L/▽b = 2(wx + b - y)
        b_gradient += -1.0 * (2/N) * (y-((w_current * x)+b_current))
        # ▽L/▽w = 2(wx + b - y)*x
        w_gradient += -1.0 * (2/N) * x * (y-((w_current * x)+b_current))
    
    new_b = b_current - (learningRate*b_gradient)
    new_w = w_current - (learningRate*w_gradient)

    return new_b,new_w

# 循环迭代梯度信息
def gradient_descent_runner(points,starting_b,starting_w,learning_rate,num_iterations):
    b = starting_b
    w = starting_w
    for i in range(num_iterations):
        b,w = step_gradient(b,w,np.array(points),learning_rate)
        print("第 {} 次 ：y = {}x+{}".format(i,w,b))
    return b,w


def run():
    points = get_data()   
    lr = 0.001
    initial_b = 0
    initial_w = 0
    iterations = 100
    print(f"Starting project descent at b = {initial_b}, w = {initial_w},error = {compute_error_for_line_given_points(initial_b,initial_w,points)}")
    print('\nRunning...')
    b,w = gradient_descent_runner(points,initial_b,initial_w,lr,iterations)
    print(f"\nAfter project descent at b = {b}, w = {w},error = {compute_error_for_line_given_points(b,w,points)}")
    print('\nb:{}，w:{}'.format(b, w))


def get_data():
    points = pd.read_csv("Pytorch/datasets/p5_data.txt",header = None).values
    return points



if __name__ == "__main__":
    run()