// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   b.cpp                                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/22 18:12:06 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/22 18:12:06 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define ll long long

ll n, m;
ll h_max = 0;

int main(void)
{
	ll sum = 0;
	ll a;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a;
		if (a > h_max)
			h_max = a;
		sum += a;
	}
	if (n == h_max)
	{
		if (sum >= 2 * n)
			std::cout << sum - n << std::endl;
		else
			std::cout << 2 * n - sum << std::endl;
	}
	else if (h_max > n)
		std::cout << sum - h_max << std::endl;
	else
		std::cout << sum - n << std::endl;
	return (0);
}