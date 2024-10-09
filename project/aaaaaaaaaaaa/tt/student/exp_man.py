import tkinter as tk
from tkinter import ttk
import pymysql
import tt.student.manageSystem as manageSystem

class eApp:
    # def __init__(self):
    
    def show_exp_info(self):
        app = manageSystem.App("实验信息：","SELECT * FROM experiments;")
        app.start()
        # self.root = tk.Tk()

    def start(self):
        # self.root.mainloop()
        self.show_exp_info()


if __name__ == '__main__':
    app = eApp()
    app.start()
	
