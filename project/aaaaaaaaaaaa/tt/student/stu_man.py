import tkinter as tk
from tkinter import ttk
import pymysql
import tt.student.manageSystem as manageSystem

class sApp(tk.Tk):
    # def __init__(self):
    def show_exp_info(self):
        app = manageSystem.App("学生信息：","SELECT * FROM students;")
        app.start()
        # self.root = tk.Tk()

    def start(self):
        # self.root.mainloop()
        self.show_exp_info()

if __name__ == '__main__':
    app = sApp()
    app.start()
