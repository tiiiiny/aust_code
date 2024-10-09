import tkinter as tk
from tkinter import ttk
import pymysql

class stuView(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Experiment Management System")
        self.geometry("1000x400")

        self.label = tk.Label(self, text="实验详细信息：", font=("Arial", 14))
        self.label.pack(pady=10)

        # 创建Treeview小部件
        self.tree = ttk.Treeview(self, show="headings")
        self.tree.pack(expand=True, fill=tk.BOTH)

        self.populate_treeview()

    def populate_treeview(self):
        try:
            db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
            cursor = db.cursor()
            cursor.execute("SELECT * FROM students where student_id=1")

            # 获取列名
            columns = [desc[0] for desc in cursor.description]
            self.tree["columns"] = columns

            # 配置列
            for col in columns:
                self.tree.heading(col, text=col)
                self.tree.column(col, width=100, anchor=tk.CENTER)

            # 插入数据
            rows = cursor.fetchall()
            for row in rows:
                self.tree.insert("", tk.END, values=row)

            db.close()
        except pymysql.MySQLError as e:
            print(f"Error connecting to MySQL: {e}")

if __name__ == '__main__':
    app = stuView()
    app.mainloop()
