// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/16 21:36:25 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/16 21:36:25 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int solve(int *a, int n, int *b, int m)
{
	int arr[101][101];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
				arr[i][j] = 0;
			else if (a[i - 1] == b[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = std::max(arr[i - 1][j], arr[i][j - 1]);
		}
	return (arr[n][m]);
}

int main(void)
{
	int n;
	int a[100];
	int m;
	int b[100];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	std::cin >> m;
	for (int i = 0; i < m; i++)
		std::cin >> b[i];
	std::cout << solve(a, n, b, m) << std::endl;
	return (0);
}