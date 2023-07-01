#ifndef LIST_H
#define LIST_H
#include <malloc.h>
#include <memory.h>
#include <iostream>
/*
	实现方案：
	使用数组来实现
*/
#define LISTBASELENGTH 20
#define LISTINCREMENT 10
template <typename T>
class List
{
private:
	T* m_listBegin;//线性表头
	unsigned int m_listLength;//线性表长度
	unsigned int m_valueNextIndex;//元素的个数 or 元素下一个位置的下标
public:
	List();
	~List();
	bool InitList();
	bool DestoryList();
	bool ClearList();
	bool ListEmpty();
	int ListLength();
	bool ListInsert(unsigned int i, T e);//一般这样插入元素的话就会要求用户知道当前元素位置。
	bool ListAppend(T e);
	void PrintList();
	void GetElem(unsigned int index,T& e);
};

template <typename T> List<T>::List()
	:
	m_listBegin(nullptr),
	m_listLength(0),
	m_valueNextIndex(0)
{
	
}

template <typename T> List<T>::~List()
{
	if (m_listBegin != nullptr)
	{
		free(m_listBegin);
		m_listBegin = nullptr;
		m_listLength = 0;
		m_valueNextIndex = 0;
	}
}

/// <summary>
/// 初始化一个线性表，有初始的长度空间。
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>如果分配空间失败则返回false</returns>
template <typename T> bool List<T>::InitList()
{
	if (m_listBegin == nullptr)
	{
		m_listLength = LISTBASELENGTH;
		m_listBegin = (T*)malloc(m_listLength * sizeof(T));
		if (m_listBegin != nullptr)
		{
			memset(m_listBegin, 0, sizeof(T) * m_listLength);
			return true;
		}
	}
	return false;
}

/// <summary>
/// 销毁线性表的空间
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T> bool List<T>::DestoryList()
{
	if (m_listBegin != nullptr)
	{
		free(m_listBegin);
		m_listBegin = nullptr;
		m_listLength = 0;
		m_valueNextIndex = 0;
	}
	return true;
}

/// <summary>
/// 清空数据
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T> bool List<T>::ClearList()
{
	m_valueNextIndex = 0;
	return true;
}

/// <summary>
/// 判断线性表是否为空
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T> bool List<T>::ListEmpty()
{
	return m_valueNextIndex == 0;
}

/// <summary>
/// 获取线性表的元素个数
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T> int List<T>::ListLength()
{
	return m_valueNextIndex;
}

/// <summary>
/// 在第i个位置之前插入元素e
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="i"></param>
/// <param name="e"></param>
/// <returns></returns>
template <typename T> bool List<T>::ListInsert(unsigned int i, T e)
{
	if (i > m_valueNextIndex+1 || i < 1)
		return false;
	if (i == m_valueNextIndex + 1)
		return ListAppend(e);
	if (m_listLength == m_valueNextIndex)
	{
		T* temp = (T*)malloc(sizeof(T) * (m_listLength + LISTINCREMENT));
		if (temp != NULL)
		{
			memcpy(temp, m_listBegin, sizeof(T) * m_listLength);
			m_listLength *= 2;
			free(m_listBegin);
			m_listBegin = temp;
		}
	}

	//移动区:[i-1,m_valueNextIndex]
	memcpy(&m_listBegin[i], &m_listBegin[i - 1], sizeof(T) * (m_valueNextIndex - i+1));
	m_listBegin[i - 1] = e;
	m_valueNextIndex++;
	return true;
}

/// <summary>
/// 在线性表末尾插入数据
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="e"></param>
/// <returns></returns>
template <typename T> bool List<T>::ListAppend(T e)
{
	if (m_valueNextIndex <= m_listLength - 1)
	{
		m_listBegin[m_valueNextIndex] = e;
		m_valueNextIndex++;
		return true;
	}
	else
	{
		T* temp = (T*)malloc(sizeof(T) * (m_listLength + LISTINCREMENT));
		if (temp != NULL)
		{
			memcpy(temp, m_listBegin, sizeof(T) * m_listLength);
			m_listLength *= 2;
			free(m_listBegin);
			m_listBegin = temp;
			m_listBegin[m_valueNextIndex] = e;
			m_valueNextIndex++;
			return true;
		}
		return false;
	}
}

/// <summary>
/// 打印线性表
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T> void List<T>::PrintList()
{
	for (unsigned int i = 0; i < m_valueNextIndex; i++)
	{
		std::cout << m_listBegin[i] << " ";
	}
	std::cout << "\n";
}

/// <summary>
/// 获取线性表第i个元素的值
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="index"></param>
/// <param name="e"></param>
template <typename T>void List<T>::GetElem(unsigned int index, T& e)
{
	if (index <= m_valueNextIndex)
		e = m_listBegin[index - 1];
}
#endif