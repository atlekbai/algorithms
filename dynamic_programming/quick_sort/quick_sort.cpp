// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   quick_sort.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/17 14:40:54 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/17 15:26:47 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

void show_arr(int *arr, int n);

int partition(int *arr, int pivot, int i, int j)
{
	int tmp;
	while (i <= j)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	return (i);
}

void quick_sort(int *arr, int i, int j)
{
	if (i >= j) return;
	int pivot = arr[(i + j) / 2];
	int index = partition(arr, pivot, i, j);
	quick_sort(arr, i, index - 1);
	quick_sort(arr, index, j);
}

int	main(int ac, char **av)
{
	int n = ac - 1;
	int arr[n];
	for (int i = 1; i < ac; i++)
		arr[i - 1] = std::atoi(av[i]);
	quick_sort(arr, 0, n - 1);
	show_arr(arr, n);
	return (0);
}

void show_arr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
		if ((i + 1) % 10 == 0) std::cout << std::endl;
	}
	std::cout << std::endl;
}
