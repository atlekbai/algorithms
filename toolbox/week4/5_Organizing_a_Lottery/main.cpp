// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/09 17:28:18 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/09 17:32:13 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>
#define MAX 50000

bool is_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (true);
	return (false);
}

int find_elem(int *count, int p, int num)
{
	int i = 0;
	for (i = 0; i < p; i++)
		if (count[i] == num)
			return (i);
	return (-1);
}

void solve(int *count, int *points, int *a, int *b, int s, int p)
{
	int arr[MAX];
	std::pair<int, int> map[MAX * 3];
	int segs = 0;
	int m = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	std::sort(a, a + s);
	std::sort(b, b + s);
	std::sort(points, points + p);
	while (i < s || j < s || k < p)
	{
		if (i < s && is_min(a[i], b[j], points[k]))
			map[m++] = std::make_pair(a[i++], 1);
		else if (j < s && is_min(b[j], a[i], points[k]))
			map[m++] = std::make_pair(b[j++], 2);
		else if (k < p && is_min(points[k], b[j], a[i]))
			map[m++] = std::make_pair(points[k++], 3);
	}
	for (int v = 0; v < m; v++)
	{
		if (map[v].second == 1)
			segs++;
		else if (map[v].second == 2)
			segs--;
		else
		{
			int idx = find_elem(count, p, map[v].first);
			arr[idx] = segs;
		}
	}
	for (int v = 0; v < p; v++)
		std::cout << arr[v] << " ";
	std::cout << std::endl;
}

int main(void)
{
	int s;
	int p;
	int a[MAX];
	int b[MAX];
	int points[MAX];
	int count[MAX];

	std::fill(a, a + MAX, 2000000000);
	std::fill(b, b + MAX, 2000000000);
	std::fill(points, points + MAX, 2000000000);
	std::cin >> s;
	std::cin >> p;
	for (int i = 0; i < s; i++)
	{
		std::cin >> a[i];
		std::cin >> b[i];
	}
	for (int i = 0; i < p; i++)
	{
		std::cin >> points[i];
		count[i] = points[i];
	}
	solve(count, points, a, b, s, p);
	return (0);
}
