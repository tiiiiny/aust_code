import tkinter as tk
from tkinter import ttk
import dbsql as dbsql

class report_submit_System:
    def __init__(self,id):
        self.id = id
        self.root = tk.Tk()
        self.root.title("学生提交报告")
        self.root.geometry("1500x650")
        
        main_frame = tk.Frame(self.root)
        main_frame.pack(expand=True, fill=tk.BOTH)
        self.personal_info_frame = tk.Frame(main_frame)
        self.booked_experiments_frame = tk.Frame(main_frame)
        self.unbooked_experiments_frame = tk.Frame(main_frame)
        self.available_labs_frame = tk.Frame(main_frame)

        self.personal_info_frame.grid(row=0, column=0, padx=5, pady=5, sticky="nsew")
        self.booked_experiments_frame.grid(row=0, column=1, padx=5, pady=5, sticky="nsew")
        self.unbooked_experiments_frame.grid(row=1, column=0, padx=5, pady=5, sticky="nsew")
        self.available_labs_frame.grid(row=1, column=1, padx=5, pady=5, sticky="nsew")

        main_frame.grid_rowconfigure(0, weight=1)
        main_frame.grid_rowconfigure(1, weight=1)
        main_frame.grid_columnconfigure(0, weight=1)
        main_frame.grid_columnconfigure(1, weight=1)

        self.create_personal_info_table()
        self.create_submitted_experiments_table()
        self.create_unsubmitted_experiments_table()
        self.create_unbooked_experiments_table()
        
        controls_frame = tk.Frame(self.root)
        controls_frame.pack(pady=10)

        self.experiment_id_label = tk.Label(self.root, text="请输入要提交报告的实验号：")
        self.experiment_id_entry = tk.Entry(self.root)
        self.lab_id_label = tk.Label(self.root, text="请输入实验内容链接：")
        self.lab_id_entry = tk.Entry(self.root)

        self.submit_button = tk.Button(self.root, text="提交报告", command=self.submit_report)
        self.close_button = tk.Button(self.root, text="关闭", command=self.close_window)

        self.experiment_id_label.grid(in_=controls_frame, row=0, column=0, padx=5, pady=5, sticky="e")
        self.experiment_id_entry.grid(in_=controls_frame, row=0, column=1, padx=5, pady=5, sticky="w")
        
        self.lab_id_label.grid(in_=controls_frame, row=1, column=0, padx=5, pady=5, sticky="e")
        self.lab_id_entry.grid(in_=controls_frame, row=1, column=1, padx=5, pady=5, sticky="w")
        
        self.submit_button.grid(in_=controls_frame, row=2, column=1, padx=5, pady=5, sticky="w")
        self.close_button.grid(in_=controls_frame, row=2, column=2, padx=5, pady=5, sticky="w")

    def create_personal_info_table(self):
        label = tk.Label(self.personal_info_frame, text="个人信息", font=("Arial", 14))
        label.pack(pady=10)
        tree = ttk.Treeview(self.personal_info_frame, show="headings")
        tree.pack(expand=True, fill=tk.BOTH)
        sql = f"SELECT * FROM student where student_id={self.id};"
        dbsql.show_data(tree,sql)

    def create_submitted_experiments_table(self):
        label = tk.Label(self.booked_experiments_frame, text="已提交", font=("Arial", 14))
        label.pack(pady=10)
        tree = ttk.Treeview(self.booked_experiments_frame, show="headings")
        tree.pack(expand=True, fill=tk.BOTH)
        sql = f"SELECT *  FROM experiment\
                        WHERE EXISTS (\
                            SELECT *\
                            FROM experimentreport\
                            WHERE experimentreport.experiment_id = experiment.experiment_id\
                            AND experimentreport.student_id = {self.id});"
        dbsql.show_data(tree,sql)

    def create_unsubmitted_experiments_table(self):
        label = tk.Label(self.available_labs_frame, text="未提交", font=("Arial", 14))
        label.pack(pady=10)
        tree = ttk.Treeview(self.available_labs_frame, show="headings")
        tree.pack(expand=True, fill=tk.BOTH)
        sql = f"SELECT * FROM experiment\
            where EXISTS (\
                SELECT * FROM experimentbooking\
                WHERE experimentbooking.experiment_id = experiment.experiment_id\
                    AND experimentbooking.student_id = {self.id})\
            AND NOT EXISTS (\
                SELECT * FROM experimentReport\
                WHERE experimentReport.experiment_id = experiment.experiment_id\
                    AND experimentreport.student_id = {self.id});"
        dbsql.show_data(tree,sql)

    def create_unbooked_experiments_table(self):
        label = tk.Label(self.unbooked_experiments_frame, text="未预约实验", font=("Arial", 14))
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

    def submit_report(self):
        experiment_id = self.experiment_id_entry.get()
        sql = f"INSERT INTO experimentreport (student_id, experiment_id, submission_time) VALUES ({self.id}, {experiment_id}, NOW())"
        dbsql.connectAndPass1(sql)
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
    app = report_submit_System(id)
    app.start()
