from tkinter import *
import experiment 
import admins
import students
import teachers 
import pymysql

def judge():
    user_id = user_entry.get()
    password = password_entry.get()
    
    try:
        db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
        cursor = db.cursor()
        
        # sql = "SELECT S.SNO FROM S WHERE S.LOGN=%s AND S.PSWD=%s"
        sql = "SELECT user_id,role FROM users WHERE user_id=%s AND password=%s"
        cursor.execute(sql, (user_id, password))
        result = cursor.fetchall()	#获取所有符合条件的结果行。#result 是一个列表，每个元素是一个包含 user_id 和 role 的元组，表示满足条件的用户记录。
        return result

    except pymysql.MySQLError as e:
        print(f"Error connecting to MySQL: {e}")
        return []

def start():

    result = judge()

    db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')

    cursor = db.cursor()
    if len(result) != 0:
        root.destroy()
        
        user_id, role = result[0]
        if role == 'student':
            # 学生登录后的操作
            sql = "SELECT student_id FROM students WHERE user_id=%s"
            cursor.execute(sql, (user_id,))
            result = cursor.fetchall()
            s = students.Student(user_id)
            s.start()
        elif role == 'teacher':
            # 教师登录后的操作
            sql = "SELECT teacher_id FROM teachers WHERE user_id=%s"
            cursor.execute(sql, (user_id,))
            result = cursor.fetchall()
            t = teachers.Teacher(user_id)
            t.start()
        elif role == 'admin':
            # 管理员登录后的操作
            sql = "SELECT user_id FROM users WHERE user_id=%s"
            cursor.execute(sql, (user_id,))
            result = cursor.fetchall()
            # a = admins.admin(user_id)
            # a.start()
            e = experiment.experiment()
            e.start()
        else:
            # 其他角色的处理逻辑
            pass

        db.close()
        return result
    else:
        Label(root, text="用户名或密码错误，请重新输入").grid(row=3, column=1)




root = Tk()
root.title("Experiment Management System")
root.geometry("300x100")

Label(root, text="         user_id").grid(row=0, column=0)
user_entry = Entry(root, width=15)
user_entry.grid(row=0, column=1)
Label(root, text="         password").grid(row=1, column=0)
password_entry = Entry(root, width=15, show="*")
password_entry.grid(row=1, column=1)

star_button = Button(root, text="login", command=start)
star_button.grid(row=2, column=1)
root.mainloop()
