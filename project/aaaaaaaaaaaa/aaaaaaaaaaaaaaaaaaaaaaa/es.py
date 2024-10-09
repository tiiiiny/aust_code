import tkinter as tk
from tkinter import ttk
import pymysql

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Experiment Management System")
        self.geometry("1300x600")

        # 创建一个框架来容纳两个表格
        frame = tk.Frame(self)
        frame.pack(expand=True, fill=tk.BOTH, padx=10, pady=10)

        # 创建实验信息的标签和Treeview
        self.experiment_label = tk.Label(frame, text="实验详细信息：", font=("Arial", 14))
        self.experiment_label.grid(row=0, column=0, sticky=tk.W, padx=10, pady=10)
        
        self.experiment_tree = ttk.Treeview(frame, show="headings")
        self.experiment_tree.grid(row=1, column=0, padx=10, pady=10, sticky=tk.EW)
        
        self.populate_experiment_treeview()

        # 创建学生信息的标签和Treeview
        self.student_label = tk.Label(frame, text="学生信息：", font=("Arial", 14))
        self.student_label.grid(row=2, column=0, sticky=tk.W, padx=10, pady=10)

        self.student_tree = ttk.Treeview(frame, show="headings")
        self.student_tree.grid(row=3, column=0, padx=10, pady=10, sticky=tk.EW)
        
        self.populate_student_treeview()

        # 设置列的扩展属性，使列填满整个窗口
        frame.columnconfigure(0, weight=1)

    def populate_experiment_treeview(self):
        try:
            db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
            cursor = db.cursor()
            cursor.execute("SELECT * FROM experiments")

            # 获取列名
            columns = [desc[0] for desc in cursor.description]
            self.experiment_tree["columns"] = columns

            # 配置列
            for col in columns:
                self.experiment_tree.heading(col, text=col)
                self.experiment_tree.column(col, width=100, anchor=tk.CENTER)

            # 插入数据
            rows = cursor.fetchall()
            for row in rows:
                self.experiment_tree.insert("", tk.END, values=row)

            db.close()
        except pymysql.MySQLError as e:
            print(f"Error connecting to MySQL: {e}")

    def populate_student_treeview(self):
        try:
            db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
            cursor = db.cursor()
            cursor.execute("SELECT * FROM students")

            # 获取列名
            columns = [desc[0] for desc in cursor.description]
            self.student_tree["columns"] = columns

            # 配置列
            for col in columns:
                self.student_tree.heading(col, text=col)
                self.student_tree.column(col, width=100, anchor=tk.CENTER)

            # 插入数据
            rows = cursor.fetchall()
            for row in rows:
                self.student_tree.insert("", tk.END, values=row)

            db.close()
        except pymysql.MySQLError as e:
            print(f"Error connecting to MySQL: {e}")

if __name__ == '__main__':
    app = App()
    app.mainloop()
