// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   warehouse.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/18 20:11:15 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/18 20:11:15 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>
#include <set>

struct box
{
	int a, b, c;
	int i;
};

struct block
{
	int h;
	std::set<int> indexes;
};

int cmp(const box &a, const box &b)
{
	int area1 = a.a * a.b;
	int area2 = b.a * b.b;
	return (area1 > area2);
}

int without_its(block *res, box *arr, int j, int i)
{
	box a = arr[i];
	int h = a.c;
	std::set<int>::iterator it;
	for (it = res[j].indexes.begin(); it != res[j].indexes.end(); it++)
	{
		std::cout << *it << " ? " << i << std::endl;
		if (arr[*it].i != a.i)
			h += arr[*it].c;
	}
	return (h);
}

int solve(box *b, const int n)
{
	box arr[10000];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		arr[j].c = b[i].a;
		arr[j].b = std::max(b[i].b, b[i].c);
		arr[j].a = std::min(b[i].b, b[i].c);
		arr[j].i = i;
		j++;

		arr[j].c = b[i].b;
		arr[j].b = std::max(b[i].a, b[i].c);
		arr[j].a = std::min(b[i].a, b[i].c);
		arr[j].i = i;
		j++;

		arr[j].c = b[i].c;
		arr[j].b = std::max(b[i].b, b[i].a);
		arr[j].a = std::min(b[i].b, b[i].a);
		arr[j].i = i;
		j++;
	}
	std::sort(arr, arr + j, cmp);
	block res[j];
	int size = j;
	for (int i = 0; i < size; i++)
	{
		res[i].h = arr[i].c;
		res[i].indexes.insert(i);
		std::cout << "i: " << i << ", h: " << arr[i].c << ", w: " << arr[i].a << ", d: " << arr[i].b << "::" << arr[i].i << std::endl;
	}

	for (int i = 1; i < size; i++)
		for (int j = 0; j < i; j++)
			if (arr[i].i != arr[j].i &&
				arr[i].a <= arr[j].a &&
				arr[i].b <= arr[j].b)
			{
				int wi = without_its(res, arr, j, i);
				// std::cout << i << " + " << j << " = " << wi << std::endl;
				if (res[i].h < without_its(res, arr, j, i))
				{
					res[i].h = without_its(res, arr, j, i);
					res[i].indexes.insert(i);
					std::cout << res[i].h << std::endl;
				}
			}
	int max = 0;
	for (int i = 0; i < size; i++)
		if (res[i].h > max)
			max = res[i].h;
	return (max);
}

int main(void)
{
	int n;
	box b[50];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> b[i].a >> b[i].b >> b[i].c;
	std::cout << solve(b, n) << std::endl;
	return (0);
}