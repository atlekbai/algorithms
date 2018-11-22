// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/12 18:45:18 by atlekbai          #+#    #+#             //
//   Updated: 2018/10/12 20:25:22 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <stdio.h>
#include <limits>
#include <iostream>
#define MAX 100000

int	main(void)
{
	int t;
	int n;

	int a;
	int knows;
	int k;
	int elems;
	int wait;

	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		knows = 0;
		k = 0;
		elems = 0;
		wait = 0;
		for (int j = 0; j < n; j++)
		{
			std::cin >> a;
			elems++;
			knows += a;
			if (wait == 0)
			{
				wait = knows;
				k++;
				if (knows >= n - elems)
				{
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
			}
			// printf("a: %d, knows: %d, k: %d, elems: %d, wait: %d\n", a, knows, k, elems, wait);
			wait--;
		}
		std::cout << k << std::endl;
	}
	return (0);
}
