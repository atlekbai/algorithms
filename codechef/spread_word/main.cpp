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

#include <iostream>
#define MAX 100000

int	solve(const int *A, const int n)
{
	int a;
	int i;
	int knows = 1;
	int k = 0;

	while (knows < n)
	{
		a = knows;
		for (i = 0; i < a && i < n; i++)
			knows += A[i];
		k++;
	}
	return (k);
}

int	main(void)
{
	int t;
	int n;
	int A[MAX] = {};

	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		for (int j = 0; j < n; j++)
			std::cin >> A[j];
		std::cout << solve(A, n) << std::endl;
	}
	return (0);
}
