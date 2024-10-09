import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# 螺线参数
p = 0.55  # 螺距，55 cm
start_circle = 16  # 点A从第16圈开始
num_points = 223  # 点的数量
# distances = [1.65] * num_points  # 223个点，距离均为1.65米
distances = [2.86] + [1.65] * (num_points - 1)

# 时间设置
time_steps = 800  # 总共800个时间步

# 螺线的角度范围
# theta = np.linspace(2 * np.pi * start_circle, 2 * np.pi * (start_circle + 4), time_steps)		# 逆时针
theta = np.linspace(2 * np.pi * start_circle, 0, time_steps)	# 顺时针

# 计算点A、B、C、D的极坐标和笛卡尔坐标
def compute_positions(theta, distances, p):
    # 计算点A的位置
    r = theta * p / (2 * np.pi)
    x_A = r * np.cos(theta)
    y_A = r * np.sin(theta)
    
    # 初始化位置列表
    x_positions = [x_A]
    y_positions = [y_A]
    
    # 计算每个点的位置
    for distance in distances:
        x_next = []
        y_next = []
        for i in range(len(theta)):
            # 计算距离点A的角度和半径
            delta_theta = distance / (theta[i] * p / (2 * np.pi))
            theta_next = theta[i] - delta_theta
            r_next = theta_next * p / (2 * np.pi)
            x_next.append(r_next * np.cos(theta_next))
            y_next.append(r_next * np.sin(theta_next))
        
        # 更新位置列表
        x_positions.append(x_next)
        y_positions.append(y_next)
        
        # 更新theta和r
        theta = theta - (distance / (theta * p / (2 * np.pi)))
    
    return x_positions, y_positions

x_positions, y_positions = compute_positions(theta, distances, p)

# 动态绘制A、B、C、D的运动轨迹
fig, ax = plt.subplots(figsize=(10 ,10))
ax.set_xlim(np.min(x_positions[0]) - 1, np.max(x_positions[0]) + 1)
ax.set_ylim(np.min(y_positions[0]) - 1, np.max(y_positions[0]) + 1)

# 初始化绘图对象
lines = [ax.plot([], [], label=f"Point {chr(ord('A') + i)}")[0] for i in range(224)]
points = [ax.plot([], [], 'o', markersize=8)[0] for _ in range(224)]

# 初始化函数
def init():
    for line in lines:
        line.set_data([], [])
    for point in points:
        point.set_data([], [])
    return lines + points

# 更新函数
def update(frame):
    for i in range(224):
        lines[i].set_data(x_positions[i][:frame], y_positions[i][:frame])
        points[i].set_data(x_positions[i][frame], y_positions[i][frame])
    return lines + points

# 创建动画
ani = FuncAnimation(fig, update, frames=time_steps, init_func=init, blit=True, interval=20)

plt.title('螺线上点A、B、C、D--------的运动轨迹')
plt.xlabel('x (m)')
plt.ylabel('y (m)')
plt.gca().set_aspect('equal', adjustable='box')
plt.legend()
plt.grid(True)
plt.show()
