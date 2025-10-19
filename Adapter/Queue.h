#pragma once
#include <cstddef>
#include "LinkedList.h"

template <typename T>
class Queue
{
private:
	LinkedList<T> list;
public:
	Queue() = default;
	void push(const T& val)
	{
		list.push_back(val);
	}
	void pop()
	{
		list.pop_front();
	}
	const T& front() const
	{
		return list.front();
	}
	const T& back() const
	{
		return list.back();
	}
	std::size_t size() const
	{
		list.size();
	}
	void clear()
	{
		list.clear();
	}
	bool empty() const
	{
		return list.empty();
	}
};
