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

            
            
def get_stuID():
    try:
            db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
            cursor = db.cursor()
            cursor.execute("SELECT * FROM students where user_id=1")
            # 插入数据
            rows = cursor.fetchall()
            student_id = rows[0][0]
            db.close()
    except pymysql.MySQLError as e:
            print(f"Error connecting to MySQL: {e}")
    return student_id
            


def book(student_id,experiment_id,lab_id):
    db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
    cursor = db.cursor()
    # sql = "insert ignore SC (SNO,CNO,GRADE) values ('%s','%s',%d)" % (experiment_id,lab_id)
    sql = f"INSERT INTO experimentbookings (student_id, lab_id, experiment_id, booking_time) VALUES ({student_id}, {lab_id}, {experiment_id}, NOW())"
    cursor.execute(sql)
    db.commit()
    db.close()

def submin(student_id,experiment_id):
    db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
    cursor = db.cursor()
    # sql = "insert ignore SC (SNO,CNO,GRADE) values ('%s','%s',%d)" % (experiment_id)
    sql = f"INSERT INTO experimentreports (student_id, experiment_id, submission_time) VALUES ({student_id}, {experiment_id}, NOW())"
    cursor.execute(sql)
    db.commit()
    db.close()

