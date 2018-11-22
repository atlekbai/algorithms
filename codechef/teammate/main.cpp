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

void print_arr(int *s, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << s[i] << " ";
	std::cout << std::endl;
}

int	solve(int *S, int n)
{
	long long mul = 1;
	long long teams = 0;
	int j;
	int i = 0;

	std::sort(S, S + n, std::greater<int>());
	while (i < n)
	{
		j = 0;
		while (j + i + 1 < n && S[i + j + 1] == S[i + 1])
			j++;
		if (j == 1)
		{
			teams++;
			teams %= THRSH;
		}
		// if (j > 1)
		else
		{
			// mul *= j;
			for (int k = j; k > 0; k -= 2)
			{
				mul *= k;
				mul %= THRSH;
			}
			if (j % 2 == 0 && i + j < n)
				i += j;
			else if (j % 2 == 1 && i + j + 1 < n)
			{
				teams++;
				teams %= THRSH;
				i += j + 1;
			}
			else
			{
				if (j % 2 == 1)
				{
					teams++;
					teams %= THRSH;
				}
				break ;
			}
			continue;
		}
		i += 2;
	}
	if (mul == 1)
		mul = 0;
	return (teams + mul - 1);
	// return (mul);
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
