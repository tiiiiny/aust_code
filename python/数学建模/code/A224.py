import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import position as pos
# 设置字体
from matplotlib.font_manager import FontProperties
font = FontProperties(fname='/System/Library/Fonts/STHeiti Medium.ttc', size=12)  # 或者其他支持中文的字体路径

# 螺线参数
p = 0.55  # 螺距，55 cm
start_circle = 6  # 点A从第16圈开始
num_points = 223 # 点的数量 -1
distances = [2.86] + [1.65] * (num_points)
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

# 获取所有点的位置
x_positions, y_positions = pos.compute_positions(distances, p, arc_length_target,theta_)

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
    for i in range(num_points + 1):
        if frame == 0:
            continue
        points[i].set_data(x_positions[i][frame-1], y_positions[i][frame-1])
        lines[i].set_data(x_positions[i][:frame], y_positions[i][:frame])
    print(f"{frame - 1}_Point A: {x_positions[0][frame-1]} {y_positions[0][frame-1]}")
    return lines + points

# 创建动画
# ani = FuncAnimation(fig, update, frames=time_steps, init_func=init, blit=True, interval=20)
ani = FuncAnimation(fig, update, frames= 419, init_func=init, blit=True, interval = 1)


plt.title('螺线上点A及后续223个点的运动轨迹', fontproperties=font)
plt.xlabel('x (m)', fontproperties=font)
plt.ylabel('y (m)', fontproperties=font)
plt.gca().set_aspect('equal', adjustable='box')
plt.grid(True)
plt.show()
