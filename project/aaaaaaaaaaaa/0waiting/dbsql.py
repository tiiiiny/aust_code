import tkinter as tk
from tkinter import ttk
import pymysql

def show_data(tree,sql):
    try:
        db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
        cursor = db.cursor()
        cursor.execute(sql,)
        # 获取列名
        columns = [desc[0] for desc in cursor.description]
        tree["columns"] = columns
        # 配置列
        for col in columns:
            tree.heading(col, text=col)
            tree.column(col, width=100, anchor=tk.CENTER)
        # 插入数据
        rows = cursor.fetchall()
        for row in rows:
            tree.insert("", tk.END, values=row)
        db.close()
    except pymysql.MySQLError as e:
        print(f"Error connecting to MySQL: {e}")

def get_ID(table,user_id):
    try:
        db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
        cursor = db.cursor()
        cursor.execute(f"SELECT * FROM {table} where user_id={user_id}")
        rows = cursor.fetchall()
        student_id = rows[0][0]
        db.close()
        return student_id
    except pymysql.MySQLError as e:
        print(f"Error connecting to MySQL: {e}")

def connectAndPass(sql):
    try:
        db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
        cursor = db.cursor()
        cursor.execute(sql)
        db.commit()
        db.close()
    except pymysql.MySQLError as e:
        print(f"Error connecting to MySQL: {e}")

def connectAndPass(sql,params):
    try:
        db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
        cursor = db.cursor()
        cursor.execute(sql,params)
        db.commit()
        db.close()
    except pymysql.MySQLError as e:
        print(f"Error connecting to MySQL: {e}")
