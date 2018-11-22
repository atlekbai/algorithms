// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   prank.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/14 17:40:36 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/14 18:02:17 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int solve(int *a, int n)
{
	int size;
	// bool chain;
	int start;
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		size = 0;
		start = i;
		// chain = false;
		// std::cout << i << ") " << a[i] << std::endl;

		if (a[i - 1] + 1 == a[i] && i - 1 == 0)
			size++;
		while (i < n && a[i - 1] + 1 == a[i] && a[i] + 1 == a[i + 1])
		{
			// std::cout << a[i - 1] << " ! " << a[i] << std::endl;
			size++;
			i++;
		}
		if (size > max)
			max = size;
		// std::cout << "size : " << size << std::endl;
		// std::cout << i << ")[2] " << a[i] << std::endl;
		// std::cout << "---------" << std::endl;
	}
	return (max);
}

int main(void)
{
	int n;
	int a[100];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	std::cout << solve(a, n) << std::endl;
	return (0);
}
