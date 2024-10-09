import tkinter as tk
from tkinter import ttk
import pymysql

class App:
    def __init__(self,tex,sql):
        self.root = tk.Tk()
        self.root.title("Experiment Management System")
        self.root.geometry("1200x600")

        # 创建主框架来容纳所有子框架
        main_frame = tk.Frame(self.root)
        # main_frame.pack(expand=True, fill=tk.BOTH)
        # 创建表格的框架
        self.personal_info_frame = tk.Frame(main_frame)
        # 将框架放入主框架中以网格布局排列
        self.personal_info_frame.grid(row=0, column=0, padx=5, pady=5, sticky="nsew")
        
        self.label = tk.Label(self.root, text=tex, font=("Arial", 14))
        self.label.pack(pady=10)
        # 创建Treeview小部件
        self.tree = ttk.Treeview(self.root, show="headings")
        self.tree.pack(expand=True, fill=tk.BOTH)
        self.populate_treeview(sql)
        
        controls_frame = tk.Frame(self.root)
        controls_frame.pack(pady=10)

        self.add_label = tk.Label(self.root, text="user_id:")
        self.add_entry = tk.Entry(self.root)
        self.delete_label = tk.Label(self.root, text="username:")
        self.delete_entry = tk.Entry(self.root)
        self.update_label = tk.Label(self.root, text="password:")
        self.update_entry = tk.Entry(self.root)
        self.search_label = tk.Label(self.root, text="role:")
        self.search_entry = tk.Entry(self.root)
        
        self.add_button = tk.Button(self.root, text="ADD", command=self.add)
        self.delete_button = tk.Button(self.root, text="DELETE", command=self.delete)
        self.update_button = tk.Button(self.root, text="UPDATE", command=self.update)
        self.search_button = tk.Button(self.root, text="SEARCH", command=self.search)
        self.q_button = tk.Button(self.root, text="X", command=self.root.quit)
        
        self.add_label.grid(in_=controls_frame,row=0, column=0, padx=5, pady=5, sticky="e")
        self.add_entry.grid(in_=controls_frame,row=0, column=1, padx=5, pady=5, sticky="w")
        self.delete_label.grid(in_=controls_frame,row=0, column=2, padx=5, pady=5, sticky="e")
        self.delete_entry.grid(in_=controls_frame,row=0, column=3, padx=5, pady=5, sticky="w")
        self.update_label.grid(in_=controls_frame,row=1, column=0, padx=5, pady=5, sticky="e")
        self.update_entry.grid(in_=controls_frame,row=1, column=1, padx=5, pady=5, sticky="w")
        self.search_label.grid(in_=controls_frame,row=1, column=2, padx=5, pady=5, sticky="e")
        self.search_entry.grid(in_=controls_frame,row=1, column=3, padx=5, pady=5, sticky="w")
        
        self.add_button.grid(in_=controls_frame,row=2, column=0, padx=5, pady=5, sticky="e")
        self.delete_button.grid(in_=controls_frame,row=2, column=1, padx=5, pady=5, sticky="w")
        self.update_button.grid(in_=controls_frame,row=2, column=2, padx=5, pady=5, sticky="e")
        self.search_button.grid(in_=controls_frame,row=2, column=3, padx=5, pady=5, sticky="w")
        self.q_button.grid(in_=controls_frame,row=2, column=4, padx=5, pady=5, sticky="w")

		# 增删改查
    def add(self):
        try:
            db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
            cursor = db.cursor()
            cursor.execute()


            db.close()
        except pymysql.MySQLError as e:
            print(f"Error connecting to MySQL: {e}")
            
    def delete(self):
        try:
            db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
            cursor = db.cursor()
            cursor.execute()


            db.close()
        except pymysql.MySQLError as e:
            print(f"Error connecting to MySQL: {e}")
            
    def update(self):
        try:
            db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
            cursor = db.cursor()
            cursor.execute()


            db.close()
        except pymysql.MySQLError as e:
            print(f"Error connecting to MySQL: {e}")
            
    def search(self):
        try:
            db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
            cursor = db.cursor()
            cursor.execute()


            db.close()
        except pymysql.MySQLError as e:
            print(f"Error connecting to MySQL: {e}")
            
    

    def populate_treeview(self,sql):
        try:
            db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
            cursor = db.cursor()
            cursor.execute(sql)

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
            
            
    def start(self):
        self.root.mainloop()


if __name__ == '__main__':
    app = App("用户信息：","SELECT * FROM experiments;")
    app.start()
