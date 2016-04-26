#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<assert.h>
#include<vector>


template<class T>
struct Less
{
	bool operator() (const T& l, const T& r)
	{
		return l < r;
	}
};

template<class T>
struct Greater
{
	bool operator() (const T& l, const T& r)
	{
		return l>r;
	}
};


template<class T,template<class> class Compare=Less>
class Heap
{
public:
	Heap()
		:_a(NULL)
	{}


	Heap(const T* a,size_t size)
	{
		for (int i = 0; i < size; i++)
		{
			_a.push_back(a[i]);
		}
		for (int i = (size - 2) / 2; i >= 0; i--)
		{
			_adjustDown(i);
		}
	}


	void _adjustDown(size_t parent)
	{
		Compare<T> com;
		size_t child = 2 * parent + 1;
		size_t size = _a.size();
		while (child<size)
		{
			if (child + 1<size && com(_a[child + 1],_a[child]))
			{
				++child;
			}
			if (com(_a[child],_a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				break;
			}
		}
	}


	void Push(const T& x)
	{
		_a.push_back(x);
		_adjustUp(_a.size()-1);
	}


	void _adjustUp(size_t child)
	{
		int parent = (child - 1) / 2;
		Compare<T> com;
		while (child>0)
		{
			if (com(_a[child],_a[parent]))
			{
				swap(_a[parent], _a[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}


	size_t Size()
	{
		size_t size = _a.size();
		return size;
	}


	bool Empty()
	{
		assert(Size() >= 0);
		return Size() == 0;
	}


	void Pop()
	{
		assert(_a.Size() > 0);
		swap(_a[0], _a[Size - 1]);
		_a.pop_back();
		_adjustDown(0);		
	}


	T& GetTop()
	{
		return _a[0];
	}


	void Print()
	{
		cout << "´ó¶ÑÐòÁÐ£º" << endl;
		for (int i = 0; i < _a.size(); i++)
		{
			cout << _a[i] << "  ";
		}
		cout << endl;
	}
public:
	vector<T> _a;
};


template<class T, template<class> class Compare = Less>
class PriorityQueue
{
public:
	void Push(const T& x)
	{
		_hp.Push(x);
	}


	void Pop()
	{
		_hp.Pop();
	}


	size_t Size()
	{
		return _hp.Size();
	}


	bool Empty()
	{
		_hp.Empty();
	}


	T& Top()
	{
		return _hp.GetTop();
	}


	void Print()
	{
		_hp.Print();
	}
private:
	Heap<T,Compare> _hp;
};