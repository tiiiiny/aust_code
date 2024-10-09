import numpy as np
from scipy.integrate import quad

# 定义弧长公式的被积函数
def integrand(theta, a):
    return a * np.sqrt(1 + theta**2)

# 定义计算弧长函数，计算从 theta_start 到 theta_end 的弧长
def arc_length_from_theta(theta_start, theta_end, a):
    # length, _ = quad(integrand, theta_start, theta_end, args=(a))
    length, error = quad(integrand, theta_start, theta_end, args=(a,))
    # print("积分结果:", length)
    # print("估计误差:", error)
    return abs(length)
# 通过迭代法，逐步递增，找到经过 1 米弧长对应的角度增量
def find_angle_for_length(theta_start, arc_length_target, a, tolerance=1e-9):
    # 初始化变量
    theta_end = theta_start - 0.01  # 初始角度增量
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

def find_angle_for_length_T(theta_start, arc_length_target, a, tolerance=1e-9):
    # 初始化变量
    theta_end = theta_start + 0.01  # 初始角度增量
    current_arc_length = 0
    # 增加 theta_end 直到找到弧长为 1 米的角度
    while True:
        current_arc_length = arc_length_from_theta(theta_start, theta_end, a)
        if abs(current_arc_length - arc_length_target) < tolerance:
            break
        # 通过逐步增加 theta_end 来找到合适的角度
        if current_arc_length < arc_length_target:
            theta_end += 0.0001  # 增量越小，精度越高
        else:
            break
    return theta_end - theta_start  # 返回角度增量



from scipy.optimize import fsolve # 导入求解方程的函数

# 定义方程，根据直线距离公式
def equation(delta_theta,a,theta_A,d):
    r_A = a * theta_A  # 点A的极径
    r_B = a * (theta_A + delta_theta)  # 点B的极径
    # 点A和点B的直线距离公式
    return np.sqrt(r_A**2 + r_B**2 - 2 * r_A * r_B * np.cos(delta_theta)) - d
# 根据两点间距离求解角度增量
def find_delta_theta(a, theta_A, distance):
    delta_theta_initial_guess = 0.001  # 可以尝试更小的初始猜测值
    # 调用fsolve，设置合理的精度
    delta_theta = fsolve(equation, delta_theta_initial_guess, args=(a, theta_A, distance), xtol=1e-8)[0]
    return delta_theta
