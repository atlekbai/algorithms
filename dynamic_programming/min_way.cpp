// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   min_way.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/14 15:57:55 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/14 16:27:29 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int find_min(int a, int b, int c)
{
	if (a < b && a < c) return (a);
	else if (b < a && b < c) return (b);
	return (c);
}

int	min_way(void)
{
	int a = 3;
	int b = 5;
	int arr[3][5] = {
		{2, 7, 3, 3, 6},
		{12, 4, 1, 9, 1},
		{1, 5, 2, 5, 4}
	};
	int weights[a][b];

	weights[0][0] = arr[0][0];
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			if (i != 0 || j != 0)
			{
				int top = (i - 1 >= 0) ? weights[i - 1][j] : 214748364;
				int left = (j - 1 >= 0) ? weights[i][j - 1] : 214748364;
				int tl = (i - 1 >= 0 && j - 1 >= 0) ? weights[i - 1][j - 1] : 214748364;
				weights[i][j] = find_min(top, left, tl) + arr[i][j];
			}
	return (arr[2][4]);
}

int	main(int ac, char **av)
{
	int res = min_way();
	std::cout << "Min way weights: " << res << std::endl;
	return (1);
}
