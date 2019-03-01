// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   npp_desc.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/18 13:25:20 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/18 13:51:12 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#define MAX_ARR 100000

void fill_arr(int *arr, int value)
{
	for (int i = 0; i < MAX_ARR; i++)
		arr[i] = value;
}

int get_max_index(int *arr, int len)
{
	int max = 0;
	int max_i = 0;
	for (int i = 0; i < len; i++)
		if (arr[i] > max)
		{
			max = arr[i];
			max_i = i;
		}
	return (max_i);
}

void get_path(int *arr, int index)
{
	if (arr[index] == -1)
	{
		std::cout << index + 1 << " ";
		return;
	}
	get_path(arr, arr[index]);
	std::cout << index + 1 << " ";
}

void solve(int *arr, int n)
{
	int N[MAX_ARR];
	int I[MAX_ARR];
	fill_arr(I, -1);
	fill_arr(N, 1);
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (arr[i] <= arr[j] && N[j] + 1 > N[i])
			{
				N[i] = N[j] + 1;
				I[i] = j;
			}
	int max_index = get_max_index(N, n);
	std::cout << N[max_index] << std::endl;
	get_path(I, max_index);
}

int	main(int ac, char **av)
{
	int arr[MAX_ARR];
	fill_arr(arr, 0);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	solve(arr, n);
	return (0);
}
