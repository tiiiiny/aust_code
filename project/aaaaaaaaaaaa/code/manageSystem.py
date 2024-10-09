import tkinter as tk
from tkinter import ttk
import pymysql
import dbsql
import datetime

class App:
    def __init__(self,tex,sql,table,le1,le2,le3,le4,le0):
        self.tex = tex
        self.sql = sql
        self.table = table
        self.le1 = le1
        self.le2 = le2
        self.le3 = le3
        self.le4 = le4
        self.le0 = le0
        self.root = tk.Tk()
        self.root.title("Experiment Management System")
        self.root.geometry("1420x600")

        main_frame = tk.Frame(self.root)
        self.personal_info_frame = tk.Frame(main_frame)
        self.personal_info_frame.grid(row=0, column=0, padx=5, pady=5, sticky="nsew")
        
        self.label = tk.Label(self.root, text=tex, font=("Arial", 14))
        self.label.pack(pady=10)
        self.tree = ttk.Treeview(self.root, show="headings")
        self.tree.pack(expand=True, fill=tk.BOTH)
        dbsql.show_data(self.tree, sql)
        
        controls_frame = tk.Frame(self.root)
        controls_frame.pack(pady=10)

        self.le1_label = tk.Label(self.root, text = "加" + le1)
        self.le1_entry = tk.Entry(self.root)
        self.le2_label = tk.Label(self.root, text = le2)
        self.le2_entry = tk.Entry(self.root)
        self.le3_label = tk.Label(self.root, text = le3)
        self.le3_entry = tk.Entry(self.root)
        self.le4_label = tk.Label(self.root, text = le4)
        self.le4_entry = tk.Entry(self.root)
        self.add_button = tk.Button(self.root, text="ADD", command=self.add)
        
        self.le01_label = tk.Label(self.root, text = f"删 {self.table}_id =")
        self.le00_entry = tk.Entry(self.root)
        self.le02_label = tk.Label(self.root, text = "的数据")
        self.delete_button = tk.Button(self.root, text="DELETE", command=self.delete)
        
        self.le11_label = tk.Label(self.root, text = f"改 {self.table}_id =")
        self.le11_entry = tk.Entry(self.root)
        self.le12_label = tk.Label(self.root, text = "这一行的信息")
        self.le13_label = tk.Label(self.root, text = "列名为")
        self.le13_entry = tk.Entry(self.root)
        self.le14_label = tk.Label(self.root, text = "中数据改为")
        self.le14_entry = tk.Entry(self.root)
        self.update_button = tk.Button(self.root, text="UPDATE", command=self.update)


        self.le21_label = tk.Label(self.root, text = f"查 {self.table}_id =")
        self.le20_entry = tk.Entry(self.root)
        self.le22_label = tk.Label(self.root, text = "的数据")
        self.search_button = tk.Button(self.root, text="SEARCH", command=self.search)
        
        self.le1_label.grid(in_=controls_frame,row=0, column=0, padx=5, pady=5, sticky="e")
        self.le1_entry.grid(in_=controls_frame,row=0, column=1, padx=5, pady=5, sticky="w")
        self.le2_label.grid(in_=controls_frame,row=0, column=2, padx=5, pady=5, sticky="e")
        self.le2_entry.grid(in_=controls_frame,row=0, column=3, padx=5, pady=5, sticky="w")
        self.le3_label.grid(in_=controls_frame,row=1, column=0, padx=5, pady=5, sticky="e")
        self.le3_entry.grid(in_=controls_frame,row=1, column=1, padx=5, pady=5, sticky="w")
        self.le4_label.grid(in_=controls_frame,row=1, column=2, padx=5, pady=5, sticky="e")
        self.le4_entry.grid(in_=controls_frame,row=1, column=3, padx=5, pady=5, sticky="w")
        self.add_button.grid(in_=controls_frame,row=3, column=2, padx=5, pady=5, sticky="e")
        
        self.le01_label.grid(in_=controls_frame,row=6, column=0, padx=5, pady=5, sticky="e")
        self.le00_entry.grid(in_=controls_frame,row=6, column=1, padx=5, pady=5, sticky="w")
        self.le02_label.grid(in_=controls_frame,row=6, column=2, padx=5, pady=5, sticky="e")
        self.delete_button.grid(in_=controls_frame,row=6, column=3, padx=5, pady=5, sticky="w")
        
        self.a_label = tk.Label(self.root, text= "                              ")
        self.a_label.grid(in_=controls_frame,row=0, column=4, padx=5, pady=5, sticky="e")
        self.b_label = tk.Label(self.root, )
        self.b_label.grid(in_=controls_frame,row=5, column=0, padx=5, pady=5, sticky="e")
        
        
        
        self.le11_label.grid(in_=controls_frame,row=0, column=5, padx=5, pady=5, sticky="e")
        self.le11_entry.grid(in_=controls_frame,row=0, column=6, padx=5, pady=5, sticky="w")
        self.le12_label.grid(in_=controls_frame,row=0, column=7, padx=5, pady=5, sticky="e")
        self.le13_label.grid(in_=controls_frame,row=1, column=5, padx=5, pady=5, sticky="e")
        self.le13_entry.grid(in_=controls_frame,row=1, column=6, padx=5, pady=5, sticky="w")
        self.le14_label.grid(in_=controls_frame,row=1, column=7, padx=5, pady=5, sticky="e")
        self.le14_entry.grid(in_=controls_frame,row=1, column=8, padx=5, pady=5, sticky="w")
        self.update_button.grid(in_=controls_frame,row=3, column=7, padx=5, pady=5, sticky="w")
        
        self.le21_label.grid(in_=controls_frame,row=6, column=5, padx=5, pady=5, sticky="e")
        self.le20_entry.grid(in_=controls_frame,row=6, column=6, padx=5, pady=5, sticky="w")
        self.le22_label.grid(in_=controls_frame,row=6, column=7, padx=5, pady=5, sticky="e")
        self.search_button.grid(in_=controls_frame,row=6, column=8, padx=5, pady=5, sticky="w")

    def add(self):
        if self.table == 'student' or self.table == 'teacher':
            sql = f"INSERT INTO {self.table} ({self.le1}, {self.le2}, {self.le3}, {self.le4}, registration_date) VALUES (%s, %s, %s, %s, %s);"
            params = (self.le1_entry.get(), self.le2_entry.get(), self.le3_entry.get(), self.le4_entry.get(), datetime.date.today())
        elif self.table == 'experiment':
            sql = f"INSERT INTO {self.table} ({self.le1}, {self.le2}, {self.le3}, {self.le4}, time) VALUES (%s, %s, %s, %s, %s);"
            params = (self.le1_entry.get(), self.le2_entry.get(), self.le3_entry.get(), self.le4_entry.get(), datetime.datetime.now())
        else:
            sql = f"INSERT INTO {self.table} ({self.le1}, {self.le2}, {self.le3}, {self.le4}) VALUES (%s, %s, %s, %s);"
            params = (self.le1_entry.get(), self.le2_entry.get(), self.le3_entry.get(), self.le4_entry.get())
        dbsql.connectAndPass(sql, params)
        self.update_ui()

    def delete(self):
        sql = f"DELETE FROM {self.table} WHERE {self.table}_id = %s;"
        params = (self.le00_entry.get(),)
        dbsql.connectAndPass(sql, params)
        self.update_ui()

    def update(self):
        sql = f"UPDATE {self.table} SET {self.le13_entry.get()} = %s WHERE {self.table}_id = %s;"
        params = (self.le14_entry.get(), self.le11_entry.get())
        dbsql.connectAndPass(sql, params)
        self.update_ui()

    def search(self):
        sql = f"SELECT * FROM {self.table} WHERE {self.table}_id = %s;"
        params = (self.le20_entry.get(),)
        dbsql.connectAndPass(sql, params)
        self.update_ui()

    def update_ui(self):
        self.close_window()
        self.__init__(self.tex,self.sql,self.table,self.le1,self.le2,self.le3,self.le4,self.le0)

    def close_window(self):
        self.root.destroy()

    def start(self):
        self.root.mainloop()


if __name__ == '__main__':
    app = App("学生信息：","SELECT * FROM student;","student","name","contact_info","user_id","class_id",2)
    app.start()
