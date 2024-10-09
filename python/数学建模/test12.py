import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# 螺线参数
p = 0.55  # 螺距，55 cm
start_circle = 16  # 点A从第16圈开始
num_points = 224  # 点的数量
distances = [2.86] + [1.65] * (num_points - 2)
speed_A = 1  # 点A的速度为1m/s

def compute_spiral_positions( distances, speed_A, p):
    # 初始化
    theta_A = [2 * np.pi * start_circle]  # 初始角度为第16圈
    r_A = [theta_A[0] * p / (2 * np.pi)]  # 根据角度计算半径
    # r_A = start_circle * p  # 也可以直接用半径
    x_A = [r_A[0] * np.cos(theta_A[0])]  # 计算初始x坐标
    y_A = [r_A[0] * np.sin(theta_A[0])]  # 计算初始y坐标
    print(theta_A)
    print(theta_A[0], r_A[0], x_A[0], y_A[0])

    # 计算后续时间步的点A位置
    for t in range ( 0,10):
        
        # delta_s = speed_A * (t - time_range[0])  # 点A在时间t的弧长变化
        # delta_s = speed_A * (t - 0)  # 点A在时间t的弧长变化
        delta_s = speed_A * 1
        r_next = r_A[-1] - delta_s  # 半径变化
        theta_next = r_next * 2 * np.pi / p  # 根据弧长变化计算新的角度
        
        
        x_A.append(r_next * np.cos(theta_next))
        y_A.append(r_next * np.sin(theta_next))
        r_A.append(r_next)
        theta_A.append(theta_next)


    # 初始化位置列表，将点A作为第一个点
    x_positions = [x_A]
    y_positions = [y_A]

    # 计算其他点的坐标
    for distance in distances:
        x_next = []
        y_next = []
        for i in range(len(theta_A)):
            delta_theta = distance / r_A[i]  # 计算距离A的角度差
            theta_next = theta_A[i] - delta_theta
            r_next = theta_next * p / (2 * np.pi)
            x_next.append(r_next * np.cos(theta_next))
            y_next.append(r_next * np.sin(theta_next))
        # 更新位置列表
        x_positions.append(x_next)
        y_positions.append(y_next)

    return x_positions, y_positions

# 计算所有点的位置
x_positions, y_positions = compute_spiral_positions( distances, speed_A, p)