import tensorflow as tf
import numpy as np
x1 = np.random.random((100,2)) * - 4 - 1
x2 = np.random.random((100,2)) * 4 + 1
x_train = np.concatenate((x1,x2))
y1 = np.zeros((100,),dtype = int)
y2 = np.ones((100,),dtype = int)
y_train = np.concatenate((y1,y2))
import matplotlib.pyplot as plt
plt.plot(x1[:,0],x1[:,1],'yo')
plt.plot(x2[:,0],x2[:,1],'bo')
plt.show()