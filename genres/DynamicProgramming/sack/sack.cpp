// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   sack.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/18 17:51:02 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/18 18:47:21 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#define MAX_ARR 300

int max(int a, int b)
{
	if (a > b) return (a);
	return (b);
}

int	solve(int W, int n, int *arr)
{
	std::cout << "B4 2D" << std::endl;
	std::cout << "W: " << W << std::endl;
	std::cout << "n: " << n << std::endl;
	int D[W + 1][n + 1];
	std::cout << "After 2d" << std::endl;
	for (int i = 0; i < W + 1; i++)
		D[i][0] = 0;
	for (int i = 0; i < n + 1; i++)
		D[0][i] = 0;
	std::cout << "OK" << std::endl;
	for (int i = 1; i <= W; i++)
		for (int j = 1; j <= n; j++)
		{
			D[i][j] = D[i][j - 1];
			if (arr[j - 1] <= i)
				D[i][j] = max(D[i][j], D[i - arr[j - 1]][j - 1] + arr[j - 1]);
		}
	return (D[W][n]);
}

int	main(void)
{
	int arr[MAX_ARR];
	for (int i = 0; i < MAX_ARR; i++) arr[i] = 0;
	int n;
	int W;
	std::cin >> W;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cout << solve(W, n, arr) << std::endl;
	return (0);
}
