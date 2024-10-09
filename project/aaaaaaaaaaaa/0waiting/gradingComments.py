import tkinter as tk
from tkinter import ttk
import dbsql as dbsql

class gradingComments_system:
    def __init__(self):
        self.root = tk.Tk()
        self.root.title("教师操作界面")
        self.root.geometry("710x500")

        main_frame = tk.Frame(self.root)
        main_frame.pack(expand=True, fill=tk.BOTH)

        self.personal_info_frame = tk.Frame(main_frame)

        self.personal_info_frame.grid(row=0, column=0, padx=5, pady=5, sticky="nsew")

        main_frame.grid_rowconfigure(0, weight=1)
        main_frame.grid_rowconfigure(1, weight=1)
        main_frame.grid_columnconfigure(0, weight=1)
        main_frame.grid_columnconfigure(1, weight=1)

        self.create_reports_info_table()
        
        controls_frame = tk.Frame(self.root)
        controls_frame.pack(pady=10)

        self.expReport_id_label = tk.Label(self.root, text="请输入要评分评语的报告号：")
        self.expReport_id_entry = tk.Entry(self.root)
        self.grade_label = tk.Label(self.root, text="请输入评分：")
        self.grade_entry = tk.Entry(self.root)
        self.comment_label = tk.Label(self.root, text="请输入评语：")
        self.comment_entry = tk.Entry(self.root)

        self.finish_button = tk.Button(self.root, text="完成", command=self.gc_finish)
        self.close_button = tk.Button(self.root, text="关闭", command=self.close_window)

        self.expReport_id_label.grid(in_=controls_frame, row=0, column=0, padx=5, pady=5, sticky="e")
        self.expReport_id_entry.grid(in_=controls_frame, row=0, column=1, padx=5, pady=5, sticky="w")
        
        self.grade_label.grid(in_=controls_frame, row=1, column=0, padx=5, pady=5, sticky="e")
        self.grade_entry.grid(in_=controls_frame, row=1, column=1, padx=5, pady=5, sticky="w")
        self.comment_label.grid(in_=controls_frame, row=2, column=0, padx=5, pady=5, sticky="e")
        self.comment_entry.grid(in_=controls_frame, row=2, column=1, padx=5, pady=5, sticky="w")
        
        self.finish_button.grid(in_=controls_frame, row=3, column=0, padx=5, pady=5, sticky="e")
        self.close_button.grid(in_=controls_frame, row=3, column=2, padx=5, pady=5, sticky="w")
        

    def create_reports_info_table(self):
        label = tk.Label(self.personal_info_frame, text="报告信息", font=("Arial", 14))
        label.pack(pady=10)
        tree = ttk.Treeview(self.personal_info_frame, show="headings")
        tree.pack(expand=True, fill=tk.BOTH)
        sql = "SELECT * FROM experimentreport;"
        dbsql.show_data(tree,sql)

    def gc_finish(self):
        expReport_id = self.expReport_id_entry.get()
        grade = self.grade_entry.get()
        comment = self.comment_entry.get()
        sql = f"UPDATE ExperimentReport \
        SET grade = '{grade}' ,feedback = '{comment}' \
        WHERE report_id = {expReport_id};"
        dbsql.connectAndPass(sql)
        self.update_ui()

    # 更新ui
    def update_ui(self):
        self.close_window()
        self.__init__()

    def close_window(self):
        self.root.destroy()

    def start(self):
        self.root.mainloop()

if __name__ == '__main__':
    app = gradingComments_system()
    app.start()
