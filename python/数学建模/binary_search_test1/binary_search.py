import numpy as np
from scipy.integrate import quad

# 给定的螺距
# p = 0.55  # 单位：米
# # 计算比例常数 a
# a = p / (2 * np.pi)

# 定义弧长公式的被积函数
def integrand(theta, a):
    return a * np.sqrt(1 + theta**2)

# 定义计算弧长函数，计算从 theta_start 到 theta_end 的弧长
def arc_length_from_theta(theta_start, theta_end, a):
    length, _ = quad(integrand, theta_start, theta_end, args=(a))
    return length

# 找到经过 1 米弧长对应的角度增量
def find_angle_for_length(theta_start, arc_length_target, a, tolerance=1e-9):
    # 初始化变量
    theta_end = theta_start - 0.1  # 初始角度增量
    current_arc_length = 0
    # 增加 theta_end 直到找到弧长为 1 米的角度
    while True:
        current_arc_length = arc_length_from_theta(theta_end, theta_start, a)
        if abs(current_arc_length - arc_length_target) < tolerance:
            break
        # 通过逐步增加 theta_end 来找到合适的角度
        if current_arc_length < arc_length_target:
            theta_end -= 0.0001  # 增量越小，精度越高
        else:
            break
    return theta_start - theta_end  # 返回角度增量

# # 初始条件
# theta_16_start = 2 * np.pi * 16  # 第十六圈的起点
# arc_length_target = 1  # 每经过 1 米的弧长
# tolerance = 1e-9  # 设置计算的精度

# 计算对应的角度增量
# theta_start = theta_16_start
# while (theta_start>=0):
#     angle_for_1m = find_angle_for_length(theta_start, arc_length_target, a, tolerance)
#     print(f"theta = {theta_start},每经过 1 米弧长的角度增量为: {angle_for_1m:.9f} 弧度")
#     theta_start -= angle_for_1m 
