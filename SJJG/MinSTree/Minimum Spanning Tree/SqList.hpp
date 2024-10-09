#pragma once
#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__
#endif

// #include <cstring>
#include <iostream>
using namespace std;

#define DEFAULT_SIZE 1000   // 缺省元素个数
#define DEFAULT_INFINITY 1000000 // 缺省无穷大

// 顺序表模板类的申明 
template <typename T>
class SqList
{
protected:
    // 顺序表的数据成员
    int length;     // 顺序表的当前长度 
    int maxLength;    // 顺序表的最大容量
    T* data;   // 元素存储空间的首地址 
public:
    // 顺序表的函数成员
    SqList(int size = DEFAULT_SIZE); // 构造一个空表 
    virtual ~SqList();   // 析构函数
    int GetLength() const;  // 取顺序表长度    
    int GetElem(int i, T& e) const; // 取顺序表中第i个元素的值 
    int SetElem(int i, const T& e); // 修改顺序表中第i个元素的值
    int DeleteElem(int i, T& e);      // 删除顺序表中第i个元素  
    int InsertElem(const T& e);        // 在顺序表表尾插入元素
};

// 构造一个空表
template <typename T>
SqList<T>::SqList(int size) {
    this->length = 0;
    this->maxLength = size;
    data = new T[DEFAULT_SIZE];
}
// 析构函数
template <typename T>
SqList<T>::~SqList() {
}
// 取顺序表长度 
template <typename T>
int SqList<T>::GetLength() const {
    return this->length;
}
// 取顺序表中第i个元素的值
template <typename T>
int SqList<T>::GetElem(int i, T& e) const {
    if ((i<this->length)&&i>=0)
		e = data[i];
    else
		cout << "Not found." << endl;
    return 0;
}
// 修改顺序表中第i个元素的值
template <typename T>
int SqList<T>::SetElem(int i, const T& e) {
    if ((i  < this->length) && i >= 0)
		this->data[i] = e;
    else
		cout << "Not found." << endl;
    return 0;
}
// 删除顺序表中第i个元素  
template <typename T>
int SqList<T>::DeleteElem(int i, T& e) {
    e = this->data[i];
    if ((i < this->length) && i >= 0) {
		for (int j = i; j < this->length - 1; j++)
			this->data[j] = this->data[j + 1];
		this->length--;
    }
    else
		cout << "Not found." << endl;
    return 0;
}
// 在顺序表表尾插入元素
template <typename T>
int SqList<T>::InsertElem(const T& e) {
    this->data[this->length] = e;
    this->length++;
    return 0;
}
