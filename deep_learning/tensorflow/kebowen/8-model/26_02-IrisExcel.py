import numpy as np
from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier

# 获取鸢尾花的数据
iris = datasets.load_diabetes()
print("iris.data.shape = ", iris.data.shape)
print("dir(iris) = ", dir(iris))
print("iris.target.shape = ", iris.target.shape)
try:
	print("iris.target_names = ", iris.target_names)
except:
	print("No iris.feature_names = ")
import xlsxwriter
import pandas as pd
# 转换数据模式
try:
    df = pd.DataFrame(iris.data, columns=iris.feature_names)
except:
    df = pd.DataFrame(iris.data, columns= ['Sepal Length(cm)', 'Sepal Width(cm)', 'Petal Length(cm)', 'Petal Width(cm)'])
df['target'] = iris.target

#print(df.head())
df.to_csv("iris.csv",sep ='\t')

writer = pd.ExcelWriter('iris.xlsx', engine='xlsxwriter')
df.to_excel(writer, sheet_name='Sheet1')
# writer.save()
# AttributeError: 'XlsxWriter' object has no attribute 'save'. Did you mean: '_save'?
# 新版pandas中save方法已经被弃用，只用writer.close()保存即可
writer.close()
