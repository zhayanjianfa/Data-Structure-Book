#ifndef LIST_H
#define LIST_H
#include <malloc.h>
#include <memory.h>
#include <iostream>
/*
	ʵ�ַ�����
	ʹ��������ʵ��
*/
#define LISTBASELENGTH 20
#define LISTINCREMENT 10
template <typename T>
class List
{
private:
	T* m_listBegin;//���Ա�ͷ
	unsigned int m_listLength;//���Ա���
	unsigned int m_valueNextIndex;//Ԫ�صĸ��� or Ԫ����һ��λ�õ��±�
public:
	List();
	~List();
	bool InitList();
	bool DestoryList();
	bool ClearList();
	bool ListEmpty();
	int ListLength();
	bool ListInsert(unsigned int i, T e);//һ����������Ԫ�صĻ��ͻ�Ҫ���û�֪����ǰԪ��λ�á�
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
/// ��ʼ��һ�����Ա��г�ʼ�ĳ��ȿռ䡣
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>�������ռ�ʧ���򷵻�false</returns>
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
/// �������Ա�Ŀռ�
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
/// �������
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T> bool List<T>::ClearList()
{
	m_valueNextIndex = 0;
	return true;
}

/// <summary>
/// �ж����Ա��Ƿ�Ϊ��
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T> bool List<T>::ListEmpty()
{
	return m_valueNextIndex == 0;
}

/// <summary>
/// ��ȡ���Ա��Ԫ�ظ���
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T> int List<T>::ListLength()
{
	return m_valueNextIndex;
}

/// <summary>
/// �ڵ�i��λ��֮ǰ����Ԫ��e
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

	//�ƶ���:[i-1,m_valueNextIndex]
	memcpy(&m_listBegin[i], &m_listBegin[i - 1], sizeof(T) * (m_valueNextIndex - i+1));
	m_listBegin[i - 1] = e;
	m_valueNextIndex++;
	return true;
}

/// <summary>
/// �����Ա�ĩβ��������
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
/// ��ӡ���Ա�
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
/// ��ȡ���Ա��i��Ԫ�ص�ֵ
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