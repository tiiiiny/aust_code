import tkinter as tk
from tkinter import messagebox
import gradingComments as gc
import manageSystem as ms
import dbsql

class teacherApp:
    def __init__(self,user_id):
        self.user_id = user_id
        self.id = dbsql.get_ID("teacher",self.user_id)
        self.root = tk.Tk()
        self.root.title("教师操作界面")

        self.exp_man_button = tk.Button(self.root, text="实验管理", command=self.exp_man_func, width=15)
        self.stu_man_button = tk.Button(self.root, text="评分评语", command=self.stu_man_func, width=15)
        self.te_man_button = tk.Button(self.root, text="搜索", command=self.te_man_func, width=15)
        self.xx_button = tk.Button(self.root, text="关闭", command=self.root.quit, width=15)

        self.exp_man_button.grid(row=0, column=0, padx=10, pady=10)
        self.stu_man_button.grid(row=0, column=1, padx=10, pady=10)
        self.te_man_button.grid(row=1, column=0, padx=10, pady=10)
        self.xx_button.grid(row=1, column=1, padx=10, pady=10)

    def exp_man_func(self):
        messagebox.showinfo("点击", "实验管理")
        # ms.App("实验信息：","SELECT * FROM experiment;","exp_name","objective","course_id","teacher_id",self.id)
        # messagebox.showinfo("点击", "实验管理")
        ms.App("实验信息：","SELECT * FROM experiment;","experiment","exp_name","objective","course_id","teacher_id",self.id)

    def stu_man_func(self):
        messagebox.showinfo("点击", "评分评语")
        r = gc.gradingComments_system()
        r.start()

    def te_man_func(self):
        # TODO
        messagebox.showinfo("点击", "搜索")
        
    
    def xx_func(self):
        messagebox.showinfo("点击", "关闭")
        # HACK
        # self.root.destroy()

    def start(self):
        self.root.mainloop()

if __name__ == "__main__":
    # root = tk.Tk()
    user_id = 2
    app = teacherApp(user_id)
    app.start()
