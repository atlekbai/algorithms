// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/17 15:43:41 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/17 16:13:03 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int solve(int *v, const int n)
{
	int part[301][n + 1];
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += v[i];
	if (sum % 3 != 0)
		return (0);
	for (int i = 0; i <= n; i++)
		part[0][i] = 1;
	for (int i = 1; i <= sum / 3; i++)
		part[i][0] = 0;
	for (int i = 1; i <= sum / 3; i++)
		for (int j = 1; j <= n; j++)
		{
			part[i][j] = part[i][j - 1];
			if (i >= v[j - 1])
				part[i][j] = part[i][j] || part[i - v[j - 1]][j - 1];
		}
/*
	for (int i = 0; i <= sum / 3; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (part[i][j] == 0)
				std::cout << "\033[0;31m";
			else
				std::cout << "\033[0;32m";
			std::cout << part[i][j] << " ";
		}
		std::cout << std::endl;
		}*/
	return (part[sum / 3][n]);
}

int main(void)
{
	int n;
	int v[20];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	std::cout << solve(v, n) << std::endl;
	return (0);
}
