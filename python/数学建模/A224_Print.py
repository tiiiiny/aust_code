import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# 螺线参数
p = 0.55  # 螺距，55 cm
start_circle = 16  # 点A从第16圈开始
num_points = 223  # 点的数量
distances = [2.86] + [1.65] * (num_points - 1)
speed_A = 1

# 时间设置
time_steps = 800  # 总共800个时间步
# 螺线的角度范围
theta = np.linspace(2 * np.pi * start_circle, 0, time_steps)  # 顺时针运动
# print(len(theta))
# print(theta)


# 计算点A及其他点的极坐标和笛卡尔坐标
def compute_positions(theta, distances, p):
    # 计算点A的位置
    r = theta * p / (2 * np.pi)
    x_A = r * np.cos(theta)
    y_A = r * np.sin(theta)
    
    # 初始化位置列表，将点A作为第一个点
    x_positions = [x_A]
    y_positions = [y_A]
    
    # 计算每个点的坐标
    for distance in distances:
        x_next = []
        y_next = []
        for i in range(len(theta)):
            # 计算距离当前点的角度差
            delta_theta = distance / (theta[i] * p / (2 * np.pi)) 
            theta_next = theta[i] + delta_theta
            r_next = theta_next * p / (2 * np.pi)
            x_next.append(r_next * np.cos(theta_next))
            y_next.append(r_next * np.sin(theta_next))
        
        # 更新位置列表
        x_positions.append(x_next)
        y_positions.append(y_next)
        
        # 更新theta
        theta = theta + (distance / (theta * p / (2 * np.pi)))
    
    return x_positions, y_positions

# 获取所有点的位置
x_positions, y_positions = compute_positions(theta, distances, p)

# 动态绘制A及其后续223个点的运动轨迹
fig, ax = plt.subplots(figsize=(8, 8))
ax.set_xlim(np.min(x_positions[0]) - 1, np.max(x_positions[0]) + 1)
ax.set_ylim(np.min(y_positions[0]) - 1, np.max(y_positions[0]) + 1)

# 初始化绘图对象：224个点（A + 223个后续点）
lines = [ax.plot([], [], label=f"Point {chr(ord('A') + i)}")[0] for i in range(num_points + 1)]
points = [ax.plot([], [], 'o', markersize=4)[0] for _ in range(num_points + 1)]

# 初始化函数
def init():
    for line in lines:
        line.set_data([], [])
    for point in points:
        point.set_data([], [])
    return lines + points

# 更新函数
def update(frame):
    for i in range(num_points + 1):
        lines[i].set_data(x_positions[i][:frame], y_positions[i][:frame])
        points[i].set_data(x_positions[i][frame-1], y_positions[i][frame-1])
    print(frame - 1,x_positions[0][frame-1], y_positions[0][frame-1])
    return lines + points

# 创建动画
ani = FuncAnimation(fig, update, frames=time_steps, init_func=init, blit=True, interval=10)

plt.title('螺线上点A及后续223个点的运动轨迹')
plt.xlabel('x (m)')
plt.ylabel('y (m)')
plt.gca().set_aspect('equal', adjustable='box')
plt.grid(True)
plt.show()
