
from tkinter import *
import tets

class Teacher:
    def __init__(self, SNO):
        self.root = Tk()
        self.root.wm_title(f"学生 {SNO} 的课程管理系统")
        self.root.geometry("900x400")

        self.SNO = SNO
        self.student_label = Label(self.root, text="学生详细信息：")
        self.course_label = Label(self.root, text="可选课程")
        self.score_label = Label(self.root, text="已修课程成绩")
        self.choose_course_label = Label(self.root, text="已选课程")
        self.course_entry_label = Label(self.root, text="请输入课程号：")
        
        self.student_text = Text(self.root, height=10, width=50)
        self.course_text = Text(self.root, height=10, width=50)
        self.score_text = Text(self.root, height=10, width=50)
        self.choose_course_text = Text(self.root, height=10, width=50)
        self.course_entry = Entry(self.root, width=10)
        self.course_button = Button(self.root, text="选课", command=self.choose_course)
        self.course_button2 = Button(self.root, text="退课", command=self.delete_course)
        self.course_button3 = Button(self.root, text="关闭", command=self.close_window)
        
        self.initialize()

    def initialize(self):
        self.student_label.grid(row=0, column=0, sticky=W, padx=10, pady=5)
        self.student_text.grid(row=1, column=0, rowspan=2, padx=10, pady=5)
        self.course_label.grid(row=0, column=1, sticky=W, padx=10, pady=5)
        self.course_text.grid(row=1, column=1, rowspan=2, padx=10, pady=5)
        self.score_label.grid(row=3, column=0, sticky=W, padx=10, pady=5)
        self.score_text.grid(row=4, column=0, rowspan=2, padx=10, pady=5)
        self.choose_course_label.grid(row=3, column=1, sticky=W, padx=10, pady=5)
        self.choose_course_text.grid(row=4, column=1, rowspan=2, padx=10, pady=5)
        self.course_entry_label.grid(row=0, column=2, padx=10, pady=5)
        self.course_entry.grid(row=1, column=2, padx=10, pady=5)
        self.course_button.grid(row=1, column=3, padx=10, pady=5)
        self.course_button2.grid(row=2, column=3, padx=10, pady=5)
        self.course_button3.grid(row=4, column=3, padx=10, pady=5)

    def choose_course(self):
        course_number = self.course_entry.get()
        try:
            tets.insert_choose_course(self.SNO, str(course_number), 0)
            self.update_ui()
        except Exception as e:
            print(f"选课失败: {e}")

    def delete_course(self):
        course_number = self.course_entry.get()
        try:
            tets.delete_choose_course(str(course_number))
            self.update_ui()
        except Exception as e:
            print(f"退课失败: {e}")

    def update_ui(self):
        self.student_text.delete(1.0, END)
        self.course_text.delete(1.0, END)
        self.score_text.delete(1.0, END)
        self.choose_course_text.delete(1.0, END)
        tets.display_student(self.student_text, self.SNO)
        tets.display_course(self.course_text, self.SNO)
        tets.display_score(self.score_text, self.SNO)
        tets.display_choose_course(self.choose_course_text, self.SNO)

    def start(self):
        self.update_ui()
        self.root.mainloop()

    def close_window(self):
        self.root.destroy()

if __name__=='__main__':
    c=Teacher('刘红')
    c.start()