// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   alice.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/10 17:18:23 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/10 17:18:24 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int main(void)
{
	int n;//num of hairs
	int m;//num of requests
	int l;//desired length
	int hairs[100000] = {};
	int r;//request

	std::cin >> n;
	std::cin >> m;
	std::cin >> l;

	int ans;
	int i = -1;
	int num_hairs;
	while (++i < n)
	{
		std::cin >> hairs[i];
		num_hairs = 0;
		while (hairs[i] > l)
		{
			num_hairs++;
			if (i + 1 == n)
				break ;
			i++;
			std::cin >> hairs[i];
		}
		if (num_hairs > 0)
			ans++;
	}
	for (int i = 0; i < m; i++)
	{
		std::cin >> r;
		if (r == 1)
		{
			int p;//p-th hairline
			int d;//growth
			std::cin >> p;
			std::cin >> d;
			p--;
			int count = 0;
			if (hairs[p] > l)
				ans += 0;
			else if (p - 1 < 0)
			{
				if (hairs[p + 1] > l && hairs[p] + d > l)
					ans += 0;
				else if (hairs[p + 1] <= l && hairs[p] + d > l)
					ans++;
			}
			else if (p - 1 >= 0)
			{
				if (hairs[p - 1] > l && hairs[p + 1] > l && hairs[p] <= l && hairs[p] + d > l)
					ans--;
				if (hairs[p - 1] <= l && hairs[p + 1] <= l && hairs[p] + d > l)
					ans++;
			}
			hairs[p] += d;
		}
		else
			std::cout << ans << std::endl;
	}
	return (0);
}