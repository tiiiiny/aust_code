import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# 螺线参数
p = 0.55  # 螺距，55 cm
b = p / (2 * np.pi)  # 螺线的极坐标参数
start_circle = 16  # 点A从第16圈开始
distance_AB = 2.86  # 点A和点B之间的距离，286 cm
distance_BC = 1.65  # 点A和点B之间的距离，286 cm

# 时间设置
time_steps = 800  # 总共500个时间步
dt = 10  # 每步的时间间隔

# 螺线的角度范围
theta_A = np.linspace(2 * np.pi * start_circle, 0, time_steps)

# 计算点A的轨迹
r_A = b * theta_A
x_A = r_A * np.cos(theta_A)
y_A = r_A * np.sin(theta_A)

# 计算点B的轨迹

def compute_position(theta_A, r_A, distance_AB, b):
    # 求点B的角度
    s_AB = distance_AB  # 弧长AB
    delta_theta = s_AB / r_A  # 点A和点B之间的角度差近似为弧长/半径
    theta_B = theta_A - delta_theta
    r_B = b * theta_B
    x_B = r_B * np.cos(theta_B)
    y_B = r_B * np.sin(theta_B)
    return x_B, y_B

x_B, y_B = compute_position(theta_A, r_A, distance_AB, b)
x_C, y_C = compute_position(theta_A, r_A, distance_BC, b)

# 动态绘制A和B的运动轨迹
fig, ax = plt.subplots(figsize=(8,8))
ax.set_xlim(np.min(x_A), np.max(x_A))
ax.set_ylim(np.min(y_A), np.max(y_A))
line_A, = ax.plot([], [], 'g-', label="Point A (Leading)")
line_B, = ax.plot([], [], 'r-', label="Point B (Following)")
line_C, = ax.plot([], [], 'b-', label="Point C (Following)")
point_A, = ax.plot([], [], 'go', markersize=8)
point_B, = ax.plot([], [], 'ro', markersize=8)
point_C, = ax.plot([], [], 'bo', markersize=8)

# 初始化函数
def init():
    line_A.set_data([], [])
    line_B.set_data([], [])
    line_C.set_data([], [])
    point_A.set_data([], [])
    point_B.set_data([], [])
    point_C.set_data([], [])
    return line_A, line_B,line_C, point_A, point_B, point_C

# 更新函数
def update(frame):
    line_A.set_data(x_A[:frame], y_A[:frame])
    line_B.set_data(x_B[:frame], y_B[:frame])
    line_C.set_data(x_C[:frame], y_C[:frame])
    point_A.set_data(x_A[frame], y_A[frame])
    point_B.set_data(x_B[frame], y_B[frame])
    point_C.set_data(x_C[frame], y_C[frame])
    return line_A, line_B,line_C, point_A, point_B, point_C

# 创建动画
ani = FuncAnimation(fig, update, frames=time_steps, init_func=init, blit=True, interval=20)

plt.title('螺线上点ABC的运动轨迹')
plt.xlabel('x (m)')
plt.ylabel('y (m)')
plt.gca().set_aspect('equal', adjustable='box')
plt.legend()
plt.grid(True)
plt.show()
