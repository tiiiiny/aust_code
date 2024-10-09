import numpy as np
import time
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib.font_manager import FontProperties

# 设置字体
font = FontProperties(fname='/System/Library/Fonts/STHeiti Medium.ttc', size=12)

# 螺线参数
p = 0.55  # 螺距，55 cm
b = p / (2 * np.pi)  # 螺距对应的极坐标参数
start_circle = 16  # 从第16圈开始
speed_A = 1
theta = np.linspace(2 * np.pi * start_circle, 0, 1000)  # 采样1000个点
# theta_peSecond = 

# 螺线的极坐标方程 r = b * theta
r = b * theta
x = r * np.cos(theta)
y = r * np.sin(theta)

# 创建图形
fig, ax = plt.subplots(figsize=(6, 6))
ax.set_xlim(np.min(x)-1, np.max(x)+1)
ax.set_ylim(np.min(y)-1, np.max(y)+1)
line, = ax.plot([], [], lw=2)

# 初始化函数
def init():
    line.set_data([], [])
    return line,

t = []
for i in range(301):
    t += [i]

# 更新函数
def update(frame,interval=1000):
    # 更新每帧的数据
    line.set_data(x[:frame], y[:frame])
    # print(time.time)
    # print(frame-1, x[frame-1], y[frame-1])
    return line,

# 创建动画
ani = FuncAnimation(fig, update, frames=len(x), init_func=init, blit=True, interval=10)

# 设置标题和显示
plt.title('螺距为55 cm的顺时针螺线（从第16圈开始）', fontproperties=font)
plt.gca().set_aspect('equal', adjustable='box')
plt.grid(True)
plt.show()
