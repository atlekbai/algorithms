// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   equal.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/19 19:20:51 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/19 19:44:27 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int ft_min(int a, int b)
{
	return (a < b) ? a : b;
}

int find(int *arr, int n, int min)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp = arr[i] - min;
		count += tmp / 5;
		count += (tmp % 5) / 2;
		count += (tmp % 5) % 2;
	}
	return (count);
}

int	solve(int *arr, int n, int min)
{
	int res = 1000000;
	for (int i = 0; i < 5; i++)
		res = ft_min(res, find(arr, n, min - i)); 
	return (res);
}

int	main(int ac, char **av)
{
	int n;
	int arr[10000];
	int min = 100000;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		if (arr[i] < min) min = arr[i];
	}
	std::cout << solve(arr, n, min) << std::endl;
	return (0);
}
