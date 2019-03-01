// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 11:45:00 by atlekbai          #+#    #+#             //
//   Updated: 2018/10/13 12:30:19 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>
#define MAX 100000
#define THRSH 1000000007

void print_arr(long long *s, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << s[i] << " ";
	std::cout << std::endl;
}

int	solve(int *S, int n)
{
	long long mul = 1;
	long long count[n];
	int j = 0;

	std::fill(count, count + n, 1);
	std::sort(S, S + n, std::greater<int>());
	for (int i = 1; i < n; i++)
		if (S[i - 1] == S[i])
			count[j]++;
		else
			j++;
	n = j + 1;
	for (int i = 0; i < n; i++)
	{
		if (count[i] <= 0) continue;
		if (count[i] % 2 == 0)
			for (int k = count[i] - 1; k > 2; k -= 2)
			{
				std::cout << "mult " << k << std::endl;
				mul *= k;
				mul %= THRSH;
			}
		else
		{
			for (int k = count[i]; k > 2; k -= 2)
			{
				std::cout << "mult " << k << std::endl;
				mul *= k;
				mul %= THRSH;
			}
			if (i != n - 1)
			{
				std::cout << "hm: mult " << count[i + 1] << std::endl;
				mul *= count[i + 1];
			}
			count[i + 1]--;
			mul %= THRSH;
		}
		print_arr(count, n);
	}
	return (mul);
}

int	main(void)
{
	int t;
	int n;
	int S[MAX];

	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		for (int j = 0; j < n; j++)
			std::cin >> S[j];
		std::cout << solve(S, n) << std::endl;
	}
	return (0);
}
