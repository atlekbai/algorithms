// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   b.cpp                                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/04 17:03:48 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/04 17:09:04 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>
#define ll long long

int n, k;
ll arr[100000];

int main(void)
{
	std::cin >> n >> k;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::sort(arr, arr + n);
	int iter = 0;
	ll gmin = 0;
	for (int i = 0; i < k; i++)
	{
		if (iter >= n)
		{
			std::cout << 0 << std::endl;
			continue;
		}
		ll min = *std::min_element(arr + iter, arr + n);
		std::cout << min - gmin << std::endl;
		gmin = min;
		while (iter < k && arr[iter] == min)
			iter++;
	}
	return (0);
}
