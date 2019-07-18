#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>
template <class T> //数组类模板定义
class Array {
private:
	T* list; //用于存放动态分配的数组内存首地址
	int size; //数组大小（元素个数）
public:
	Array(int sz = 50); //构造函数
	Array(const Array<T> &a); //复制构造函数
	~Array(); //析构函数
	Array<T> & operator = (const Array<T> &rhs); //重载"=“
	 T & operator [] (int i); //重载"[]”
	 const T & operator [] (int i) const; //重载"[]”常函数
	operator T * (); //重载到T*类型的转换
	//operator const T * () const;
	int getSize() const; //取数组的大小
	void resize(int sz); //修改数组的大小
}; 

#endif