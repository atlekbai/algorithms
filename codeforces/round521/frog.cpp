// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   frog.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/16 16:41:17 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/16 16:49:39 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

long long int solve(int a, int b, int k)
{
	long long int res = 0;
	long long int n = k - 1;

	res += (n + 1) / 2 * a;
	res -= (n - (n + 1) / 2) * b;
	res += (k % 2 == 1) ? a : -b;
	return (res);
}

int main(void)
{
	int t;
	int a, b, k;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> a;
		std::cin >> b;
		std::cin >> k;
		std::cout << solve(a, b, k) << std::endl;
	}
	return (0);
}
