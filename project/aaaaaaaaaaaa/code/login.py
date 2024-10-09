from tkinter import *
import admin
import student 
import teacher 
import pymysql

def judge():
    user_id = user_entry.get()
    password = password_entry.get()
    
    try:
        db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
        cursor = db.cursor()
        sql = "SELECT user_id,role FROM user WHERE user_id=%s AND password=%s"
        cursor.execute(sql, (user_id, password))
        result = cursor.fetchall()
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
            sql = "SELECT student_id FROM student WHERE user_id=%s"
            cursor.execute(sql, (user_id,))
            result = cursor.fetchall()
            app = student.studentApp(user_id)
            app.start()
        elif role == 'teacher':
            sql = "SELECT teacher_id FROM teacher WHERE user_id=%s"
            cursor.execute(sql, (user_id,))
            result = cursor.fetchall()
            t = teacher.teacherApp(user_id)
            t.start()
        elif role == 'admin':
            sql = "SELECT user_id FROM user WHERE user_id=%s"
            cursor.execute(sql, (user_id,))
            result = cursor.fetchall()
            a = admin.adminApp(user_id)
            a.start()
        else:
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
