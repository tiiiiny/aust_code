import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import binary_search as bs
import position as pos

# 螺线参数
p = 0.55  # 螺距，55 cm
start_circle = 16  # 点A从第16圈开始
num_points = 223  # 点的数量 - 1
l1, l2 = 3.41, 2.2	# 龙头的长度，龙身或龙尾的长度
D, d = 0.055 ,0.275 # 孔径（孔的直径）为5.5cm,孔的中心距离最近的板头 27.5 cm
d1,d2 = l1 - D - d * 2, l2 - D - d * 2 # 龙头、龙身或龙尾的两孔中心距离
distances = [d1] + [d2] * (num_points - 1)	# len = 223
speed_A = 1  # 点A的速度为1m/s
arc_length_target = 1  # 每经过 1 米的弧长
tolerance = 1e-9

# 时间设置
# time_steps = 800  # 总共800个时间步
total_time = 440  # 总时间300秒
# time_range = np.linspace(0, total_time + 1, time_steps)  # 0到300秒的时间点


# 计算所有点的位置
theta_start = start_circle * 2 * np.pi   # 点A从第16圈开始
x_positions, y_positions = pos.compute_positions( distances, p, arc_length_target,theta_start)
speeds = pos.calculate_speed( distances, p)
# print(speeds[1])

# 准备保存到Excel的内容
headers1 = []  # 行标题，初始空值
headers1 = [f"龙头x (m)", f"龙头y (m)"]  # 龙头的x, y
for i in range(1, num_points-1):  # 龙身的各节
    headers1 += [f"第{i}节龙身x (m)", f"第{i}节龙身y (m)"]
headers1 += [f"龙尾x (m)", f"龙尾y (m)",f"龙尾（后）x (m)", f"龙尾（后）y (m)"]  # 龙尾的x, y
headers2 = []  # 行标题，初始空值
headers2 = [f"龙头 (m/s)"]  # 龙头
for i in range(1, num_points-1):  # 龙身的各节
    headers2 += [f"第{i}节龙身 (m/s)"]
headers2 += [f"龙尾 (m/s)",f"龙尾（后） (m/s)"]  # 龙尾

# 生成列标题，时间0-300秒
time_columns = []
time_columns = [f"{int(t)} s" for t in np.arange(0, total_time + 1, 1)]

# 创建数据表格
# 位置数据
data1 = []
# 遍历所有整数秒的时间步，提取各点的位置
for step_index in range(total_time + 1):  # 提取每秒时刻的数据
    row = []  
    for i in range(len(x_positions)):  # len(x_positions) = 224, 点数
        # 使用格式化字符串保留六位小数，并确保显示为 '8.800000' 形式
        row.append(f"{x_positions[i][step_index]:.6f}")
        row.append(f"{y_positions[i][step_index]:.6f}")
    data1.append(row)
# 将数据转置并保存到pandas DataFrame中
df1 = pd.DataFrame(data1,index=time_columns, columns=headers1)
# 速度数据
data2 = []
# row = [""] * 224
# data2.append( row )
# print(len(speeds))
# print(len(speeds[0]))
# print(len(speeds[1]))
# print(len(speeds[2]))
# print(len(speeds[220]))

# 遍历所有整数秒的时间步，提取各点的速度
# for step_index in range(total_time + 1):  # 提取每秒时刻的数据
for step_index in range(total_time + 1):  # 提取每秒时刻的数据
    row = []  
    # for i in range(len(speeds) + 1 ):  # len(speeds)  + 1= 225, 点数
    for i in range(num_points + 1):  # len(speeds)  + 1= 225, 点数
        # if step_index >= len(speeds[i]):
        #     print(f"step_index={step_index}, len(speeds[i])={len(speeds[i])}, i={i}")
        #     raise IndexError(f"step_index {step_index} 超出 speeds[{i}] 的范围")
        # 使用格式化字符串保留六位小数，并确保显示为 '8.800000' 形式
        row.append(f"{speeds[i][step_index]:.6f}")
    data2.append(row)
# 将数据转置并保存到pandas DataFrame中
df2 = pd.DataFrame(data2,index=time_columns, columns=headers2)

# 创建一个 Excel 文件并写入两个工作表
with pd.ExcelWriter('result1.xlsx', engine='openpyxl') as writer:
    df1.T.to_excel(writer, sheet_name='位置', index=True)
    df2.T.to_excel(writer, sheet_name='速度', index=True)
print("数据已成功保存到 result1.xlsx")
