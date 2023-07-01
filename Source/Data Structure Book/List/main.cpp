#include <iostream>
#include "List.h"
int main()
{
	List<int> listA;
	listA.InitList();
	listA.ListAppend(1);
	listA.ListAppend(2);
	listA.ListAppend(3);
	listA.ListAppend(4);
	listA.ClearList();
	return 1;
}