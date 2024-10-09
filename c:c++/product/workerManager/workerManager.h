#pragma once							//防止头文件重复包含
#include<iostream>
#include<string>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "test.txt"
using namespace std;//使用标准命名空间
class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	//展示菜单
	void Show_Menu();
	//退出程序
	void ExitSystem();
	
	int m_EmpNum;						//记录职工人数
	Worker** m_EmpArray;				//职工数组？指针
	// 指向指针的指针
	// 指向 Worker* 类型指针的指针，这通常用于表示一个指针？数组
	// 用来指向一个包含多个 Worker 对象指针的数组，每个元素都是一个指向 Worker 对象的指针
	// 用于动态分配和管理多个 Worker 对象
	// Worker* m_EmpArray0;				//职工数组？

	//添加职工
	void AddEmp();
	//保存文件
	void SaveFile();
	
	bool m_FileIsEmpty;					//判断文件是否为空标志


	//统计文件中的人数
	int Get_EmpNum();
	//初始化职工
	void Init_Emp();
	//显示职工
	void Show_Emp();
	//判断职工是否存在
	int IsExist(int id);
	//删除职工
	void Del_Emp();
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//员工排序
	void Sort_Emp();
	//清空数据
	void Clean_File();
	//析构函数
	~WorkerManager();
};
