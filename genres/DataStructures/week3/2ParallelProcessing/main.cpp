// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/12 14:16:19 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/12 14:16:19 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

struct Thread
{
	long long i;
	long long t;

	Thread &operator=(Thread const &a)
	{
		this->i = a.i;
		this->t = a.t;
		return (*this);
	}
};


class Heap
{
private:
	Thread arr[100000];
	long long size;
	long long maxSize;
public:
	Heap(void)
	{
		init(1);
	}

	Heap(long long n)
	{
		init(n);
	}
	
	void init(long long n)
	{
		size = 0;
		maxSize = n;
		for (long long i = 0; i < n; i++)
			arr[i].i = i;
	}

	void changePriority(long long i, long long p)
	{
		arr[i].t += p;
		siftDown(i);
	}

	void insert(long long p)
	{
		if (size == maxSize)
			return ;
		arr[size].t = p;
		siftUp(size);
		size++;
	}

	void siftDown(long long i)
	{
		long long maxIndex = i;
		long long l = leftChild(i);
		long long r = rightChild(i);
		
		if (l < size && (arr[l].t < arr[maxIndex].t ||
			(arr[l].t <= arr[maxIndex].t && arr[l].i < arr[maxIndex].i)))
			maxIndex = l;
		if (r < size && (arr[r].t < arr[maxIndex].t || 
			(arr[r].t <= arr[maxIndex].t && arr[r].i < arr[maxIndex].i)))
			maxIndex = r;
		if (i != maxIndex)
		{
			swap(arr[i], arr[maxIndex]);
			siftDown(maxIndex);
		}
	}

	void siftUp(long long i)
	{
		while (i > 0 && arr[i].t < arr[parent(i)].t)
		{
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}

	Thread	const &front(void)
	{
		return (arr[0]);
	}

	long long parent(long long i)
	{
		return ((i - 1) / 2);
	}

	long long leftChild(long long i)
	{
		return (2 * i + 1);
	}

	long long rightChild(long long i)
	{
		return (2 * i + 2);
	}

	void print(void) const
	{
		for (long long i = 0; i < size; i++)
			std::cout << arr[i].i << " : " << arr[i].t << std::endl;
	}
};

std::vector<std::pair<long long, long long> > output;

class Manager
{
public:
	long long		size;
	Heap	heap;
	Manager(long long n)
	{
		size = n;
		heap.init(n);
		for (long long i = 0; i < n; i++)
			heap.insert(0);
	}
	void	addJob(long long p)
	{
		output.push_back(std::make_pair(heap.front().i, heap.front().t));
		heap.changePriority(0, p);
	}
};

int main(void)
{
	long long a;
	long long n;
	long long m;
	std::cin >> n >> m;
	Manager man(n);
	for (long long i = 0; i < m; i++)
	{
		std::cin >> a;
		man.addJob(a);
	}
	for (long long i = 0; i < output.size(); i++)
		std::cout << output[i].first << " " << output[i].second << std::endl;
	return (0);
}