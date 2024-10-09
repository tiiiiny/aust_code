
from tkinter import *
import tets
import pymysql
import numpy as np

class experiment:
    def __init__(self):
        self.root = Tk()
        self.root.wm_title("实验管理系统")
        self.root.geometry("900x400")

        self.experiment_label = Label(self.root, text="实验详细信息：",)
        # self.course_label = Label(self.root, text="可选实验")
        # self.score_label = Label(self.root, text="已修实验成绩")
        # self.choose_course_label = Label(self.root, text="已选实验")
        # self.course_entry_label = Label(self.root, text="请输入实验id：")
        
        self.experiment_text = Text(self.root, height=50, width=100)
        # self.course_text = Text(self.root, height=10, width=50)
        # self.score_text = Text(self.root, height=10, width=50)
        # self.choose_course_text = Text(self.root, height=10, width=50)
        
        # self.course_entry = Entry(self.root, width=5)
        
        # self.course_button = Button(self.root, text="预约实验", )
        # self.course_button2 = Button(self.root, text="完成实验", )
        # self.course_button3 = Button(self.root, text="关闭",)
        # self.course_button3 = Button(self.root, text="关闭",command=self.root.quit)
        self.course_button3 = Button(self.root, text="关闭",)
        
    def inilize(self):
        self.experiment_label.grid(row=0, column=0, sticky=W)
        self.experiment_text.grid(row=1, column=0, sticky=E)
        # self.course_label.grid(row=0, column=1, sticky=W)
        # self.course_text.grid(row=1, column=1, sticky=E)
        # self.score_label.grid(row=3, column=0, sticky=W)
        # self.score_text.grid(row=4, column=0, sticky=E)
        # self.choose_course_label.grid(row=3, column=1, sticky=W)
        # self.choose_course_text.grid(row=4, column=1, sticky=E)
        # self.course_entry_label.grid(row=0, column=3)
        # self.course_entry.grid(row=1, column=3)
        # self.course_button.grid(row=1, column=4)
        # self.course_button2.grid(row=2, column=4)
        # self.course_button3.grid(row=4, column=4)

    # # yuyue
    # def yuyue_e(self):
    #     course_number = self.course_entry.get()
    #     tets.insert_choose_course(self.experiment_id, str(course_number), 0)
    #     self.update_ui()

    # # 退课
    # def delete_course(self):
    #     course_number = self.course_entry.get()
    #     tets.delete_choose_course(str(course_number))
    #     self.update_ui()
    
    # 显示实验信息
    def display_experiment(self,text):
        db = pymysql.connect(host='localhost', user='admin', password='000', database='test', charset='utf8')
        cursor = db.cursor()
        sql = "select * from experiments"
        cursor.execute(sql)
        col=[]
        for i in list(np.array(cursor.description)):
            col.append(i[0])
        text.insert(END,col)
        text.insert(END,'\n')

        result = cursor.fetchall()

        for row in result:
            text.insert(END,row)
            text.insert(END,'\n')
        db.close()

    # 更新ui
    def update_ui(self):
        self.experiment_text.delete(1.0, END)
        # self.course_text.delete(1.0, END)
        # self.score_text.delete(1.0, END)
        # self.choose_course_text.delete(1.0, END)
        
        self.display_experiment(self.experiment_text)
        # tets.display_student(self.student_text, self)
        # tets.display_(self.score_text, self)
        # tets.display_choose_course(self.choose_course_text, self)

    def start(self):
        self.inilize()
        self.update_ui()
        self.root.mainloop()

    def close_window(self):
        self.root.destroy()

if __name__=='__main__':
    e=experiment()
    e.start()