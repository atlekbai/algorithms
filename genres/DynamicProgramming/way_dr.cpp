// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   way_dr.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/14 15:28:47 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/14 15:36:57 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int	way(int n)
{
	int arr[n][n];

	arr[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] == 0)
			{
				int top = 0;
				int left = 0;
				top = (i - 1 >= 0) ? arr[i - 1][j] : 0;
				left = (j - 1 >= 0) ? arr[i][j - 1] : 0;
				arr[i][j] = top + left;
			}

	for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < n; j++)
			std::cout << arr[i][j] << "\t";
		std::cout << std::endl;
	}
	return (arr[n - 1][n - 1]);
}

int	main(int ac, char **av)
{
	int res = way(std::atoi(av[1]));
	std::cout << "Ways to get to end: " << res << std::endl;
	return (0);
}
