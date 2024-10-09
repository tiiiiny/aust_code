import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
# 设置字体
from matplotlib.font_manager import FontProperties
font = FontProperties(fname='/System/Library/Fonts/STHeiti Medium.ttc', size=12)  # 或者其他支持中文的字体路径

# 螺线参数
p = 0.55  # 螺距，55 cm
start_circle = 16  # 点A从第16圈开始
num_points = 223 # 点的数量 -1
distances = [2.86-0.055] + [1.65-0.055] * (num_points)
time_steps = 800  # 时间步/采样点数
# 螺线的角度范围
theta = np.linspace(2 * np.pi * start_circle, 0, time_steps)  # 顺时针运动

# 图底
def plot_circle(total_circles, p, time_steps):
    # 螺线的极坐标方程 r = b * theta
    theta = np.linspace(2 * np.pi * total_circles , 0, time_steps)  # 顺时针运动
    r = p / (2 * np.pi) * theta
    x = r * np.cos(theta)
    y = r * np.sin(theta)
    plt.plot(x, y, label=f'Spiral with pitch = {p} m, start at circle {start_circle + 2}')

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

# 底图，动态绘制A及其后续223个点的运动轨迹
fig, ax = plt.subplots(figsize=(8, 8))
plot_circle( start_circle + 10 , p, time_steps)
ax.set_xlim(np.min(x_positions[0]) - 3.5, np.max(x_positions[0]) + 3.5)
ax.set_ylim(np.min(y_positions[0]) - 3.5, np.max(y_positions[0]) + 3.5)

# 初始化绘图对象：224个点（A + 223个后续点）
points = [ax.plot([], [], 'o', markersize=4)[0] for _ in range(num_points + 1)]
lines = [ax.plot([], [], label=f"Point {chr(ord('A') + i)}")[0] for i in range(num_points +1)]

# 初始化函数
def init():
    for point in points:
        point.set_data([], [])
    for line in lines:
        line.set_data([], [])
    return lines + points

# 更新函数
def update(frame):
    print(f"Frame {frame}")
    for i in range(num_points + 1):
        points[i].set_data(x_positions[i][frame-1], y_positions[i][frame-1])
        lines[i].set_data(x_positions[i][:frame], y_positions[i][:frame])
    return lines + points

# 创建动画
# ani = FuncAnimation(fig, update, frames=time_steps, init_func=init, blit=True, interval=20)
ani = FuncAnimation(fig, update, frames= 1000, init_func=init, blit=True, interval = 100)


plt.title('螺线上点A及后续223个点的运动轨迹', fontproperties=font)
plt.xlabel('x (m)', fontproperties=font)
plt.ylabel('y (m)', fontproperties=font)
plt.gca().set_aspect('equal', adjustable='box')
plt.grid(True)
plt.show()
