// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   equal_c11.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/20 09:16:07 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/20 10:45:19 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#define MIN(a, b) ((a < b) ? a : b)

int find(std::vector<int> arr, int min)
{
	int count = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		int tmp = arr[i] - min;
		count += tmp / 5;
		count += tmp % 5 / 2;
		count += tmp % 5 % 2 / 1;
	}
	return (count);
}

int	equal(std::vector<int> v)
{
	int minim = *std::min_element(v.begin(), v.end());
	int res = 10000;
	for (int i = 0; i < 5; i++)
		res = MIN(res, find(v, minim - i));
	return (res);
}

int	main(void)
{
	std::vector<int> arr = {1, 2, 3, 4, 6};
	std::cout << equal(arr) << std::endl;
}
