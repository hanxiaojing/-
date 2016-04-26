#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "PriorityQueue.hpp"

void Test()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	PriorityQueue<int,Greater> pq;
	pq.Push(10);
	pq.Push(11);
	pq.Push(13);
	pq.Push(12);
	pq.Push(16);
	pq.Push(18);
	pq.Push(15);
	pq.Push(17);
	pq.Push(14);
	pq.Push(19);       

	pq.Print();
}


int main()
{
	Test();
	system("pause");
	return 0;
}