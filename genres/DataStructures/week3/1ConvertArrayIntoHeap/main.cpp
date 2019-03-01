// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/12 13:08:28 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/12 13:08:28 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>

std::vector<std::pair<int,int> > res;

void	swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

class Heap
{
private:
	int arr[100000];
	int size;
	int maxSize;
public:
	Heap(int n)
	{
		init(n);
	}

	Heap(int *array, int n)
	{
		init(n);
		for (int i = 0; i < n; i++)
			arr[i] = array[i];
		size = n;
		for (int i = (n - 1) / 2; i >= 0; i--)
			siftDown(i);
		// print();
	}

	void print(void) const
	{
		for (int i = 0; i < size; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	void init(int n)
	{
		size = 0;
		maxSize = n;
	}

	int extractRoot(void)
	{
		int result = arr[0];
		arr[0] = arr[size - 1];
		siftDown(0);
		size--;
		return (result);
	}

	void insert(int p)
	{
		if (size == maxSize)
			return ;
		arr[size] = p;
		siftUp(size);
		size++;
	}

	void siftDown(int i)
	{
		int maxIndex = i;
		int l = leftChild(i);
		int r = rightChild(i);
		if (l < size && arr[l] < arr[maxIndex])
			maxIndex = l;
		if (r < size && arr[r] < arr[maxIndex])
			maxIndex = r;
		if (i != maxIndex)
		{
			swap(arr[i], arr[maxIndex]);
			res.push_back(std::make_pair(i, maxIndex));
			siftDown(maxIndex);
		}
	}

	void siftUp(int i)
	{
		while (i > 0 && arr[i] < arr[parent(i)])
		{
			swap(arr[i], arr[parent(i)]);
			res.push_back(std::make_pair(i, parent(i)));
			i = parent(i);
		}
	}

	int parent(int i)
	{
		if (i == 1 || i == 2)
			return (0);
		return ((i - 1) / 2);
	}

	int leftChild(int i)
	{
		return (2 * i + 1);
	}

	int rightChild(int i)
	{
		return (2 * i + 2);
	}
};

int main(void)
{
	int arr[100000];
	int n;
	std::cin >> n;	
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	Heap heap(arr, n);
	std::cout << res.size() << std::endl;
	for (int i = 0; i < res.size(); i++)
		std::cout << res[i].first << " " << res[i].second << std::endl;
	return (0);
}