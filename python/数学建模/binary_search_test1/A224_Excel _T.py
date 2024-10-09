import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
# import binary_search as bs
import bs

# 螺线参数
p = 0.55  # 螺距，55 cm
start_circle = 16  # 点A从第16圈开始
num_points = 223  # 点的数量
distances = [2.86] + [1.65] * (num_points - 1)
speed_A = 1  # 点A的速度为1m/s
arc_length_target = 1  # 每经过 1 米的弧长
tolerance = 1e-9

# 时间设置
time_steps = 800  # 总共800个时间步
total_time = 300  # 总时间300秒
time_range = np.linspace(0, total_time + 1, time_steps)  # 0到300秒的时间点

# 计算螺线上点A的弧长公式 s = r * theta，并确保A每秒移动1米
# def compute_spiral_positions(time_range, distances, speed_A, p):
def compute_spiral_positions(distances, p):
    # 初始化
    theta_A = [2 * np.pi * start_circle]  # 初始角度为第16圈
    r_A = [theta_A[0] * p / (2 * np.pi)]  # 根据角度计算半径
    x_A = [r_A[0] * np.cos(theta_A[0])]  # 计算初始x坐标
    y_A = [r_A[0] * np.sin(theta_A[0])]  # 计算初始y坐标

    # 计算后续时间步的点A位置
    # for t in time_range[1:]:
    #     delta_s = speed_A * (t - time_range[0])  # 点A在时间t的弧长变化
    #     r_next = r_A[-1] - delta_s  # 半径变化
    #     theta_next = r_next * 2 * np.pi / p  # 根据弧长变化计算新的角度
    #     x_A.append(r_next * np.cos(theta_next))
    #     y_A.append(r_next * np.sin(theta_next))
    #     r_A.append(r_next)
    #     theta_A.append(theta_next)
    theta_start = theta_A[0]
    a = p / (2 * np.pi)
    n = 300
    # for t in time_range[1:]:
    # while theta_start >= 0:
    while n >= 0:
        n -= 1
        # delta_s = speed_A * (t - time_range[0])  # 点A在时间t的弧长变化
        # angle_for_1m = bs.find_angle_for_length(theta_start, arc_length_target, a, tolerance)
        angle_for_1m = bs.find_angle_decrease(a,1, theta_start)
        r_next = r_A[-1] - angle_for_1m * a  # 半径变化
        # theta_next = r_next * 2 * np.pi / p  # 根据弧长变化计算新的角度
        theta_next = theta_start - angle_for_1m  
        x_A.append(r_next * np.cos(theta_next))
        y_A.append(r_next * np.sin(theta_next))
        r_A.append(r_next)
        theta_A.append(theta_next)
        theta_start = theta_next

    # 初始化位置列表，将点A作为第一个点
    x_positions = [x_A]
    y_positions = [y_A]

    # 计算其他点的坐标
    # for distance in distances:
    #     x_next = []
    #     y_next = []
    #     for i in range(len(theta_A)):
    #         delta_theta = distance / r_A[i]  # 计算距离A的角度差
    #         theta_next = theta_A[i] - delta_theta
    #         r_next = theta_next * p / (2 * np.pi)
    #         x_next.append(r_next * np.cos(theta_next))
    #         y_next.append(r_next * np.sin(theta_next))
    #     # 更新位置列表
    #     x_positions.append(x_next)
    #     y_positions.append(y_next)

    return x_positions, y_positions


# 计算所有点的位置
x_positions, y_positions = compute_spiral_positions( distances, p)
for i in range(300):
    print(x_positions[0][i],y_positions[0][i])

