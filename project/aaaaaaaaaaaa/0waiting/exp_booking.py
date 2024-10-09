import tkinter as tk
from tkinter import ttk
import dbsql as dbsql

class ExperimentBookingSystem:
    def __init__(self,id):
        self.id = id
        self.root = tk.Tk()
        self.root.title("学生预约实验")
        self.root.geometry("1500x700")
        # 创建主框架来容纳所有子框架
        main_frame = tk.Frame(self.root)
        main_frame.pack(expand=True, fill=tk.BOTH)
        # 创建四个表格的框架
        self.personal_info_frame = tk.Frame(main_frame)
        self.booked_experiments_frame = tk.Frame(main_frame)
        self.unbooked_experiments_frame = tk.Frame(main_frame)
        self.available_labs_frame = tk.Frame(main_frame)
        # 将框架放入主框架中以网格布局排列
        self.personal_info_frame.grid(row=0, column=0, padx=5, pady=5, sticky="nsew")
        self.booked_experiments_frame.grid(row=0, column=1, padx=5, pady=5, sticky="nsew")
        self.unbooked_experiments_frame.grid(row=1, column=0, padx=5, pady=5, sticky="nsew")
        self.available_labs_frame.grid(row=1, column=1, padx=5, pady=5, sticky="nsew")
        # 配置网格布局，使框架随窗口大小调整
        main_frame.grid_rowconfigure(0, weight=1)
        main_frame.grid_rowconfigure(1, weight=1)
        main_frame.grid_columnconfigure(0, weight=1)
        main_frame.grid_columnconfigure(1, weight=1)

        self.create_personal_info_table()
        self.create_booked_experiments_table()
        self.create_unbooked_experiments_table()
        self.create_available_labs_table()
        
        controls_frame = tk.Frame(self.root)
        controls_frame.pack(pady=10)
        # 创建输入字段和按钮
        self.experiment_id_label = tk.Label(self.root, text="请输入要预约的实验号：")
        self.experiment_id_entry = tk.Entry(self.root)
        self.lab_id_label = tk.Label(self.root, text="请输入要预约的实验室号：")
        self.lab_id_entry = tk.Entry(self.root)

        self.book_button = tk.Button(self.root, text="预约实验", command=self.book_experiment)
        # self.submit_button = tk.Button(self.root, text="提交报告", command=self.submit_report)
        self.close_button = tk.Button(self.root, text="关闭", command=self.close_window)

        # 将输入字段和按钮放入一个单独的框架中
        self.experiment_id_label.grid(in_=controls_frame, row=0, column=0, padx=5, pady=5, sticky="e")
        self.experiment_id_entry.grid(in_=controls_frame, row=0, column=1, padx=5, pady=5, sticky="w")
        self.lab_id_label.grid(in_=controls_frame, row=1, column=0, padx=5, pady=5, sticky="e")
        self.lab_id_entry.grid(in_=controls_frame, row=1, column=1, padx=5, pady=5, sticky="w")
        self.book_button.grid(in_=controls_frame, row=2, column=0, padx=5, pady=5, sticky="e")
        # self.submit_button.grid(in_=controls_frame, row=2, column=1, padx=5, pady=5, sticky="w")
        self.close_button.grid(in_=controls_frame, row=2, column=2, padx=5, pady=5, sticky="w")

    def create_personal_info_table(self):
        label = tk.Label(self.personal_info_frame, text="个人信息", font=("Arial", 14))
        label.pack(pady=10)
        tree = ttk.Treeview(self.personal_info_frame, show="headings")
        tree.pack(expand=True, fill=tk.BOTH)
        sql = f"SELECT * FROM student where student_id={self.id}"
        dbsql.show_data(tree,sql)
        

    def create_booked_experiments_table(self):
        label = tk.Label(self.booked_experiments_frame, text="已预约", font=("Arial", 14))
        label.pack(pady=10)
        tree = ttk.Treeview(self.booked_experiments_frame, show="headings")
        tree.pack(expand=True, fill=tk.BOTH)
        sql = f"SELECT *  FROM experiment\
                        WHERE EXISTS (\
                            SELECT *\
                            FROM experimentbooking\
                            WHERE experimentbooking.experiment_id = experiment.experiment_id\
                            AND experimentbooking.student_id = {self.id});"
        dbsql.show_data(tree,sql)

    def create_unbooked_experiments_table(self):
        label = tk.Label(self.unbooked_experiments_frame, text="未预约", font=("Arial", 14))
        label.pack(pady=10)
        tree = ttk.Treeview(self.unbooked_experiments_frame, show="headings")
        tree.pack(expand=True, fill=tk.BOTH)
        sql = f"SELECT experiment_id,exp_name,objective,course_id,teacher_id FROM experiment\
            where NOT EXISTS (\
                SELECT * FROM experimentbooking\
                WHERE experimentbooking.experiment_id = experiment.experiment_id\
                    AND experimentbooking.student_id = {self.id})\
            AND NOT EXISTS (\
                SELECT * FROM experimentReport\
                WHERE experimentReport.experiment_id = experiment.experiment_id\
                    AND experimentreport.student_id = {self.id});"
        dbsql.show_data(tree,sql)

    def create_available_labs_table(self):
        label = tk.Label(self.available_labs_frame, text="空闲实验室", font=("Arial", 14))
        label.pack(pady=10)
        tree = ttk.Treeview(self.available_labs_frame, show="headings")
        tree.pack(expand=True, fill=tk.BOTH)
        sql =  " select * from lab where status = \"available\"; "
        dbsql.show_data(tree,sql)

    def book_experiment(self):
        experiment_id = self.experiment_id_entry.get()
        lab_id = self.lab_id_entry.get()
        sql = f"INSERT INTO experimentbooking (student_id, lab_id, experiment_id, booking_time) VALUES ({self.id}, {lab_id}, {experiment_id}, NOW())"
        dbsql.connectAndPass(sql)
        self.update_ui(self.id)

    def update_ui(self,id):
        self.close_window()
        self.__init__(id)

    def close_window(self):
        self.root.destroy()

    def start(self):
        self.root.mainloop()

if __name__ == '__main__':
    id = 2
    app = ExperimentBookingSystem(id)
    app.start()
