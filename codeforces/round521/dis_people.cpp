// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   dis_people.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/16 16:54:32 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/16 17:04:19 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int solve(int *a, int n)
{
	int i_n = 0;
	int res = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1)
		{
			a[i + 1] = 0;
			res++;
		}
	}
	// for (int i = 0; i < n; i++)
	// 	std::cout << a[i] << " ";
	// std::cout << std::endl;
	return (res);
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
