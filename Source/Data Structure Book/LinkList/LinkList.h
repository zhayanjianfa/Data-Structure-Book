#ifndef LINKLIST_H
#define LINKLIST_H
#include <malloc.h>
#include <memory.h>


template<typename T> class LinkList
{
private:
	struct LNode
	{
		LNode* next;
		T value;
	};
	LNode* m_nodeHead;
public:
	LinkList();
	~LinkList();
	bool InitList();
	bool DestoryList();
	bool ClearList();
	bool ListEmpty();
	int ListLength();
	bool ListInsert(unsigned int i, T e);//一般这样插入元素的话就会要求用户知道当前元素位置。
	bool ListAppend(T e);
	void PrintList();
	void GetElem(unsigned int index, T& e);
};

template <typename T> LinkList<T>::LinkList()
	:
	m_nodeHead(nullptr)
{

}

template <typename T> LinkList<T>::~LinkList()
{
	while (m_nodeHead != nullptr)
	{
		LNode* temp = m_nodeHead->next;
		free(m_nodeHead);
		m_nodeHead = temp;
	}
}
template <typename T> bool LinkList<T>::InitList()
{
	//if (m_nodeHead == nullptr)
	//{
	//	m_nodeHead = (LNode*)malloc(m_listLength * sizeof(LNode));
	//	if (m_nodeHead != nullptr)
	//	{
	//		m_nodeHead->next = nullptr;
	//		m_nodeHead->value = 0;//哨兵
	//		return true;
	//	}
	//}
	//return false;
	return true;//感觉放置个头节点没啥作用，增加了复杂度
}

/// <summary>
/// 销毁链表的空间
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T> bool LinkList<T>::DestoryList()
{
	while(m_nodeHead != nullptr)
	{
		LNode* temp = m_nodeHead->next;
		free(m_nodeHead);
		m_nodeHead = temp;
	}
	return true;
}

/// <summary>
/// 清空数据
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T> bool LinkList<T>::ClearList()
{
	while (m_nodeHead != nullptr)
	{
		LNode* temp = m_nodeHead->next;
		free(m_nodeHead);
		m_nodeHead = temp;
	}
	return true;
}

/// <summary>
/// 判断线性表是否为空
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T> bool LinkList<T>::ListEmpty()
{
	return m_nodeHead == nullptr;
}

/// <summary>
/// 获取线性表的元素个数
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <typename T> int LinkList<T>::ListLength()
{
	//如果有头节点，这里会减小遍历的复杂度
	LNode* p = m_nodeHead;
	int count = 0;
	while (p != nullptr)
	{
		p = p->next;
		count++;
	}
	return count;
}

/// <summary>
/// 在第i个位置之前插入元素e，i属于[1,listLength+1]，这里可插在末尾
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="i"></param>
/// <param name="e"></param>
/// <returns></returns>
template <typename T> bool LinkList<T>::ListInsert(unsigned int i, T e)
{
	if (i < 1)
		return false;
	

	if (m_nodeHead == nullptr && i==1)
	{
		m_nodeHead = (LNode*)malloc(sizeof(LNode));
		m_nodeHead->value = e;
		m_nodeHead->next = nullptr;
	}
	else if (m_nodeHead != nullptr)
	{
		int count = 0;
		LNode* p = m_nodeHead;
		LNode* q = p;
		while (p != nullptr)
		{
			count++;//当前位置
			if (i == count)//找到位置
			{
				LNode* node = (LNode*)malloc(sizeof(LNode));
				node->value = e;
				if (i == 1)
				{
					node->next = m_nodeHead;
					m_nodeHead = node;
					return true;
				}
				else
				{
					q->next = node;
					node->next = p;
					return true;
				}
			}
			else
			{
				q = p;
				p = p->next;
			}
		}
		if (count == i)
		{
			LNode* node = (LNode*)malloc(sizeof(LNode));
			node->value = e;
			p->next = node;
			node->next = nullptr;
			return true;
		}
		return false;
	}

}

/// <summary>
/// 在线性表末尾插入数据
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="e"></param>
/// <returns></returns>
template <typename T> bool LinkList<T>::ListAppend(T e)
{
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node->value = e;
	node->next = nullptr;
	
	if(m_nodeHead == nullptr)
	{
		m_nodeHead = node;
	}
	else
	{
		LNode* p = m_nodeHead;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = node;
	}
	return true;
}

/// <summary>
/// 打印线性表
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T> void LinkList<T>::PrintList()
{
	LNode* p = m_nodeHead;
	while (p != nullptr)
	{
		std::cout << p->value << " ";
		p = p->next;
	}
	std::cout << "\n";
}

/// <summary>
/// 获取线性表第i个元素的值
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="index"></param>
/// <param name="e"></param>
template <typename T>void LinkList<T>::GetElem(unsigned int index, T& e)
{
	int count = 0;
	LNode* p = m_nodeHead;
	while (p != nullptr)
	{
		count++;
		if (count == index)
		{
			e = p->value;
			break;
		}
		p = p->next;
	}
}
#endif