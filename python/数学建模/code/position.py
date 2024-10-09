import numpy as np
import binary_search as bs



# 计算螺线上点A的弧长公式 s = r * theta，并确保A每秒移动1米
# def compute_spiral_positions(time_range, distances, speed_A, p):
def pre_positions( p,arc_length_target,theta_start0):
    # 初始化
    tolerance = 1e-9
    # theta_A = [2 * np.pi * start_circle]  # 初始角度为第16圈
    ''''''
    # theta_A = [2 * np.pi * start_circle]  # 初始角度为第16圈
    theta_A = [theta_start0]  # 初始角度为第16圈
    r_A = [ (theta_A[0] * p / (2 * np.pi) )]  # 根据角度计算半径
    x_A = [r_A[0] * np.cos(theta_A[0])]  # 计算初始x坐标
    y_A = [r_A[0] * np.sin(theta_A[0])]  # 计算初始y坐标
    
    '''计算后续时间步的点A位置'''
    theta_start = theta_A[0]
    a = p / (2 * np.pi)
    n = 440			# total_time
    # for t in time_range[1:]:
    # while theta_start >= 0:
    while n >= 0 and theta_start >= 0:
        n -= 1
        # delta_s = speed_A * (t - time_range[0])  # 点A在时间t的弧长变化
        angle_for_1m = bs.find_angle_for_length(theta_start, arc_length_target, a, tolerance)
        r_next = r_A[-1] - angle_for_1m * a  # 半径变化
        # theta_next = r_next * 2 * np.pi / p  # 根据弧长变化计算新的角度
        theta_next = theta_start - angle_for_1m    
        x_A.append(r_next * np.cos(theta_next))
        y_A.append(r_next * np.sin(theta_next))
        r_A.append(r_next)
        theta_A.append(theta_next)
        theta_start = theta_next
    return x_A,y_A,theta_A,a
def pre_positions_T( p,arc_length_target,theta_start):
    # 初始化
    tolerance = 1e-9
    # theta_A = [2 * np.pi * start_circle]  # 初始角度为第16圈
    theta_A = theta_start  # 初始角度为第16圈
    # r_A = [theta_A[0] * p / (2 * np.pi)]  # 根据角度计算半径
    
    theta_start = theta_A[0]
    a = p / (2 * np.pi)
    n = 440			# total_time
    # for t in time_range[1:]:
    # while theta_start >= 0:
    while n >= 0 :
        n -= 1
        # delta_s = speed_A * (t - time_range[0])  # 点A在时间t的弧长变化
        angle_for_1m = bs.find_angle_for_length(theta_start, arc_length_target, a, tolerance)
        # r_next = r_A[-1] + angle_for_1m * a  # 半径变化
        # theta_next = r_next * 2 * np.pi / p  # 根据弧长变化计算新的角度
        theta_next = theta_start + angle_for_1m  
        # r_A.append(r_next)
        theta_A.append(theta_next)
        theta_start = theta_next
    return theta_A

def compute_positions(distances, p, arc_length_target,theta_start):
    x_A,y_A,theta_A,a = pre_positions( p,arc_length_target,theta_start)
    # 初始化位置列表，将点A作为第一个点
    x_positions = [x_A]
    y_positions = [y_A]

    '''计算其他点的坐标'''
    for distance in distances:
        x_next = []
        y_next = []
        delta_theta = 0  # 距离A的角度差
        for i in range(len(theta_A)):
            # delta_theta = distance / r_A[i]  # 计算距离A的角度差
            delta_theta = bs.find_delta_theta(a,theta_A[i] + delta_theta,distance)
            theta_next = theta_A[i] + delta_theta
            r_next = theta_next * p / (2 * np.pi)
            x_next.append(r_next * np.cos(theta_next))
            y_next.append(r_next * np.sin(theta_next))
            theta_A[i] += delta_theta  # 更新角度差
        # 更新位置列表
        x_positions.append(x_next)
        y_positions.append(y_next)

    return x_positions, y_positions


def calculate_speed(distances, p):
    total_time = 440
    speeds_A = [1] * (total_time + 1)	# 300s
    speeds_A[0] = 1
    speeds = [speeds_A]
    t0 = 0.1
    arc_min = t0 * speeds_A[0]
    t = 1
    arc_length_target = t * speeds_A[0]
    tolerance = 1e-9
    a = p / (2 * np.pi)  
    
    start_circle = 16
    theta_A = [2 * np.pi * start_circle]  # 初始角度为第16圈
    # print(theta_A)
    
    delta_theta2 =  bs.find_angle_for_length(theta_A[0],arc_min,  a,tolerance)
    # print(delta_theta2)
    delta_theta1 =  bs.find_angle_for_length_T(theta_A[0],arc_min,  a,tolerance)
    # print(delta_theta1)
    # delta_theta1 = bs.find_angle_for_length_T(theta_A[0],arc_min,  a,tolerance)
    theta_A1 = [theta_A[0] + delta_theta1]
    theta_A2 = [theta_A[0] - delta_theta2]
    # x_A1,y_A1,theta_A10,a1 = pre_positions( p,arc_min,theta_A1)
    # print(theta_A10)
    # x_A1,y_A1,theta_A1,a1 = pre_positions( p,arc_length_target,theta_A10[1])
    ''''''
    x_A1,y_A1,theta_A1,a1 = pre_positions( p,arc_length_target,theta_A1[0])
    # print(theta_A1)
    # print(theta_A2)
    # x_A2,y_A2,theta_A20,a2 = pre_positions( p,arc_min,theta_A2)
    # print(theta_A20)
    x_A2,y_A2,theta_A2,a2 = pre_positions( p,arc_length_target,theta_A2[0])
    # print(theta_A2)
    for distance in distances:    
        delta_theta1, delta_theta2 = 0, 0
        speed = [0]
        for i in range(len(theta_A1)):
            delta_theta1 = bs.find_delta_theta(a,theta_A1[i] - delta_theta1,distance)
            delta_theta2 = bs.find_delta_theta(a,theta_A2[i] - delta_theta2,distance)
            theta_start = theta_A1[i] + delta_theta1
            theta_end = theta_A2[i] + delta_theta2
            delta_spiral = bs.arc_length_from_theta(theta_end , theta_start,a)
            speed.append(delta_spiral/(t0 * 2))
            theta_A1[i] += delta_theta1
            theta_A2[i] += delta_theta2
        speeds.append( speed )
        
    return speeds


# p = 0.55  # 螺距，55 cm
# start_circle = 16  # 点A从第16圈开始
# num_points = 223  # 点的数量 - 1
# l1, l2 = 3.41, 2.2	# 龙头的长度，龙身或龙尾的长度
# D, d = 0.055 ,0.275 # 孔径（孔的直径）为5.5cm,孔的中心距离最近的板头 27.5 cm
# d1,d2 = l1 - D - d * 2, l2 - D - d * 2 # 龙头、龙身或龙尾的两孔中心距离
# distances = [d1] + [d2] * (num_points - 1)	# len = 223
# speeds = calculate_speed(distances , p)

# print(speeds[0])
# print(speeds[1])
# print(speeds[2])
