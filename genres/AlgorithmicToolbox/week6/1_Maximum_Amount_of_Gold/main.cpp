// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/17 15:04:32 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/17 15:21:49 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int solve(const int W, int *arr, const int n)
{
	int **S = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		S[i] = new int[W + 1];

	for (int i = 0; i <= n; i++)
		S[i][0] = 0;
	for (int i = 0; i <= W; i++)
		S[0][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= W; j++)
		{
			S[i][j] = S[i - 1][j];
			if (arr[i - 1] <= j)
				if (S[i][j] < S[i - 1][j - arr[i - 1]] + arr[i - 1])
					S[i][j] = S[i - 1][j - arr[i - 1]] + arr[i - 1];
		}
	return (S[n][W]);
}

int main(void)
{
	int W;
	int n;
	int arr[300];

	std::cin >> W >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cout << solve(W, arr, n) << std::endl;
	return (0);
}
