import tkinter as tk
from tkinter import messagebox
import manageSystem as ms

class adminApp:
    def __init__(self,user_id):
        self.id = user_id
        self.root = tk.Tk()
        self.root.title("管理员界面")

        self.exp_man_button = tk.Button(self.root, text="实验管理", command=self.exp_man_func, width=15)
        self.stu_man_button = tk.Button(self.root, text="学生管理", command=self.stu_man_func, width=15)
        self.te_man_button = tk.Button(self.root, text="教师管理", command=self.te_man_func, width=15)
        self.lab_man_button = tk.Button(self.root, text="实验室管理", command=self.lab_man_func, width=15)
        self.course_man_button = tk.Button(self.root, text="课程管理", command=self.course_man_func, width=15)
        self.class_button = tk.Button(self.root, text="班级管理", command=self.class_func, width=15)
        self.user_button = tk.Button(self.root, text="用户管理", command=self.user_func, width=15)
        self.xx_button = tk.Button(self.root, text="X", command=self.root.quit, width=15)

        self.exp_man_button.grid(row=0, column=0, padx=10, pady=10)
        self.stu_man_button.grid(row=0, column=1, padx=10, pady=10)
        self.te_man_button.grid(row=0, column=2, padx=10, pady=10)
        self.lab_man_button.grid(row=0, column=3, padx=10, pady=10)
        self.course_man_button.grid(row=1, column=0, padx=10, pady=10)
        self.class_button.grid(row=1, column=1, padx=10, pady=10)
        self.user_button.grid(row=1, column=2, padx=10, pady=10)
        self.xx_button.grid(row=1, column=3, padx=10, pady=10)

    def exp_man_func(self):
        messagebox.showinfo("点击", "实验管理")
        ms.App("实验信息：","SELECT * FROM experiment;","experiment","exp_name","objective","course_id","teacher_id",self.id)

    def stu_man_func(self):
        messagebox.showinfo("点击", "学生管理")
        ms.App("学生信息：","SELECT * FROM student;","student","name","contact_info","user_id","class_id",self.id)

    def te_man_func(self):
        messagebox.showinfo("点击", "教师管理")
        ms.App("教师信息：","SELECT * FROM teacher;","teacher","name","gender","contact_info","user_id",self.id)

    def lab_man_func(self):
        messagebox.showinfo("点击", "实验室管理")
        app = ms.App("实验室信息：","SELECT * FROM lab;","lab","lab_name","capacity","equipment_list","status",self.id)

    def course_man_func(self):
        messagebox.showinfo("点击", "课程管理")
        ms.App("课程信息：","SELECT * FROM course;","course","course_name","credits","teacher_id","semester",self.id)

    def class_func(self):
        messagebox.showinfo("点击", "班级管理")
        ms.App("班级信息：","SELECT * FROM class;","class","class_name","course_id","major","numberOfStudents",self.id)

    def user_func(self):
        messagebox.showinfo("点击", "用户管理")
        ms.App("用户信息：","SELECT * FROM user;","user","username","password","role","confirm password",self.id)

    def xx_func(self):
        messagebox.showinfo("点击", "X")
        # self.root.quit()

    def start(self):
        self.root.mainloop()
        
if __name__ == "__main__":
    user_id = 2
    app = adminApp(user_id)
    app.start()
