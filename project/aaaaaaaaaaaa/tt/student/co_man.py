import tkinter as tk
from tkinter import ttk
import pymysql
import tt.student.manageSystem as manageSystem

class cApp:
    # def __init__(self):
        
    def show_exp_info(self):
        app = manageSystem.App("课程信息：","SELECT * FROM courses;")
        app.start()
        # self.root = tk.Tk()

    def start(self):
        # self.root.mainloop()
        self.show_exp_info()

if __name__ == '__main__':
    app = cApp()
    app.start()
