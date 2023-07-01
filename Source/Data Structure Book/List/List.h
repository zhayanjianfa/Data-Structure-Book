#ifndef LIST_H
#define LIST_H
#include <malloc.h>
#include <memory.h>
/*
	实现方案：
	使用数组来实现
*/
template <typename T>
class List
{
private:
	T* m_listBegin;
	unsigned int m_listLength;//线性表长度
	unsigned int m_valueIndex;
public:
	List();
	~List();
	bool InitList();
	bool DestoryList();
	bool ClearList();
	bool ListEmpty();
	int ListLength();
	bool ListInsert(int i, T e);//一般这样插入元素的话就会要求用户知道当前元素位置。
	void ListAppend(T e);

};




template <typename T> List<T>::List()
	:
	m_listBegin(nullptr),
	m_listLength(10),
	m_valueIndex(0)
{
	
}

template <typename T> List<T>::~List()
{
	if (m_listBegin == nullptr)
		free(m_listBegin);
}

template <typename T> bool List<T>::InitList()
{
	if (m_listBegin == nullptr)
	{
		m_listBegin = (T*)malloc(m_listLength * sizeof(T));
		if (m_listBegin != nullptr)
			return true;
	}
	return false;
}

template <typename T> bool List<T>::DestoryList()
{
	free(m_listBegin);
	m_listBegin = nullptr;
	m_valueIndex = 0;
	return true;
}

template <typename T> bool List<T>::ClearList()
{
	free(m_listBegin);
	m_listBegin = nullptr;
	return true;
}

template <typename T> bool List<T>::ListEmpty()
{
	return m_valueIndex == 0;
}

template <typename T> int List<T>::ListLength()
{
	return m_valueIndex;
}

template <typename T> bool List<T>::ListInsert(int i, T e)
{
	return true;
}
template <typename T> void List<T>::ListAppend(T e)
{
	if (m_valueIndex <= m_listLength - 1)
	{
		m_listBegin[m_valueIndex] = e;
		m_valueIndex++;
	}
	else
	{
		T* temp = (T*)malloc(sizeof(T) * m_listLength * 2);
		memcpy(temp, m_listBegin, sizeof(T) * m_listLength);
		m_listLength *= 2;
		free(m_listBegin);
		m_listBegin = temp;
	}
}

#endif