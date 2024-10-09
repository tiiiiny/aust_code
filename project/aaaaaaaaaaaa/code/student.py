import tkinter as tk
from tkinter import messagebox
import exp_booking
import report_submit
import dbsql

class studentApp:
    def __init__(self, user_id):
        self.user_id = user_id
        self.id = dbsql.get_ID("student",self.user_id)
        self.root = tk.Tk()
        self.root.title("学生操作界面")
        self.exp_man_button = tk.Button(self.root, text="预约实验", command=self.exp_man_func, width=15)
        self.stu_man_button = tk.Button(self.root, text="提交报告", command=self.stu_man_func, width=15)
        self.te_man_button = tk.Button(self.root, text="搜索", command=self.te_man_func, width=15)
        self.xx_button = tk.Button(self.root, text="关闭", command=self.root.quit, width=15)
        self.exp_man_button.grid(row=0, column=0, padx=10, pady=10)
        self.stu_man_button.grid(row=0, column=1, padx=10, pady=10)
        self.te_man_button.grid(row=1, column=0, padx=10, pady=10)
        self.xx_button.grid(row=1, column=1, padx=10, pady=10)

    def exp_man_func(self):
        messagebox.showinfo("点击", "预约实验")
        e = exp_booking.ExperimentBookingSystem(self.id)
        e.start()

    def stu_man_func(self):
        messagebox.showinfo("点击", "提交报告")
        r = report_submit.report_submit_System(self.id)
        r.start()

    def te_man_func(self):
        messagebox.showinfo("点击", "搜索")

    def xx_func(self):
        messagebox.showinfo("点击", "关闭")
        self.root.quit()

    def start(self):
        self.root.mainloop()

if __name__ == "__main__":
    user_id = 4
    app = studentApp(user_id)
    app.start()
