// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   edit_dist.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/18 14:28:13 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/18 15:18:50 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int diff(char s1, char s2)
{
	if (s1 == s2)
		return (0);
	return (1);
}

int min(int a, int b, int c)
{
	if (a <= b && a <= c) return (a);
	if (b <= a && b <= c) return (b);
	return (c);
}

int	edit_distance(std::string s1, std::string s2)
{
	int n = s1.length() + 1;
	int m = s2.length() + 1;
	int D[n][m];
	int c;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (i == 0) D[i][j] = j;
			else if (j == 0) D[i][j] = i;
			else
			{
				c = diff(s1[i - 1], s2[j - 1]);
				D[i][j] = min(D[i - 1][j] + 1, D[i][j - 1] + 1, D[i - 1][j - 1] + c);
			}
		}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << D[i][j] << "  ";
		std::cout << std::endl;
	}
	return (D[n - 1][m - 1]);
}

int	main(void)
{
	std::string s1;
	std::string s2;
	std::cin >> s1;
	std::cin >> s2;
	std::cout << edit_distance(s1, s2) << std::endl;
	return (0);
}
