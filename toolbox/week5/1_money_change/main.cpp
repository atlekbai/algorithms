// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/12 22:35:46 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/12 22:51:00 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int solve(const int n)
{
	const int denom[3] = {1, 3, 4};
	int ans[1000] = {};
	for (int i = 0; i < 3; i++)
		ans[denom[i]] = 1;
	for (int i = 1; i <= n; i++)
		if (ans[i] == 0)
		{
			int best = 100000;
			for (int j = 0; j < 3; j++)
			{
				if (i - denom[j] >= 0 && ans[i - denom[j]] + 1 < best)
					best = ans[i -denom[j]] + 1;
			}
			ans[i] = best;
		}
	return (ans[n]);
}

int main(void)
{
	int n;
	std::cin >> n;
	std::cout << solve(n) << std::endl;
	return (0);
}
