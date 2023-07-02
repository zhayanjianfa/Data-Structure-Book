// LinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include "LinkList.h"

int main()
{
	LinkList<int> listA;
	listA.InitList();
	listA.ListAppend(1);
	listA.ListAppend(2);
	listA.ListAppend(3);
	listA.ListAppend(4);
	listA.PrintList();
	listA.ListInsert(1, 0);
	listA.PrintList();
	listA.ListInsert(2, 9);
	listA.PrintList();
	int a = 0;
	listA.GetElem(2, a);
	std::cout << a << std::endl;
	listA.ClearList();
	return 1;
}