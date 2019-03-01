// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/16 21:46:49 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/16 21:46:49 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>

int ft_max(int a, int b, int c)
{
	int arr[3] = {a, b, c};
	std::sort(arr, arr + 3);
	return (arr[2]);
}

int solve(int *a, int n, int *b, int m, int *c, int l)
{
	int arr[101][101][101];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= l; k++)
			{
				if (i == 0 || j == 0 || k == 0)
					arr[i][j][k] = 0;
				else if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
					arr[i][j][k] = arr[i - 1][j - 1][k - 1] + 1;
				else
					arr[i][j][k] = ft_max(arr[i - 1][j][k],
										  arr[i][j - 1][k],
										  arr[i][j][k - 1]);
			}
	return (arr[n][m][l]);
}

int main(void)
{
	int n;
	int a[100];
	int m;
	int b[100];
	int l;
	int c[100];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	std::cin >> m;
	for (int i = 0; i < m; i++)
		std::cin >> b[i];
	std::cin >> l;
	for (int i = 0; i < l; i++)
		std::cin >> c[i];
	std::cout << solve(a, n, b, m, c, l) << std::endl;
	return (0);
}